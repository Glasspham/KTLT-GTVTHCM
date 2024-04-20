#include<iostream>
#include<Windows.h>
#include<iomanip> 
#include<fstream>
#include<vector>
#include<set>
using namespace std;

// Khai báo các biến toàn cục
struct point {
    int x, y;
};
// Các hướng di chuyển (phải, trái, xuống, lên)
int dx[] = { 0, 0, 1, -1 }; 
int dy[] = { 1, -1, 0, 0 };
int ROW, COL; // Khai báo kích thước maze
vector<vector<int>> matrix;
vector<vector<bool>> visited; // Lữu trữ lại những điểm đã đi qua sẽ không đi lại
vector<point> path; // Lưu trữ đường đi của robot

// Setup giao diện
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void clearScreen() {
    system("cls");
}

void Drawn() {
    cout << "============================" << endl;
}

void DrawnRobot() {
    setColor(FOREGROUND_RED);
    cout << setw(22) << "  |_________|   " << endl;
    cout << setw(22) << "  | O     O |   " << endl;
    cout << setw(22) << "  |    0    |   " << endl;
    cout << setw(22) << "\\ |_________| / " << endl;
    cout << setw(22) << " \\|         |/  " << endl;
    cout << setw(22) << "  |  Glass  |   " << endl;
    cout << setw(22) << "  |         |   " << endl;
    cout << setw(22) << "  |_________|   " << endl;
    resetColor();
}

// Hàm xử lý dữ liệu
void InputFile() {
    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cerr << "Khong the mo file input.txt" << endl;
        exit(1);
    }
    infile >> ROW >> COL;
    if (ROW <= 0 || COL <= 0) {
        cerr << "Kich thuoc ma tran khong hop le" << endl;
        exit(1);
    }
    matrix.resize(ROW, vector<int>(COL, 0));
    visited.resize(ROW, vector<bool>(COL, false));
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int value;
            infile >> value;
            if (value < 0) {
                cerr << "Gia tri khong hop le o vi tri (" << i << ", " << j << ")" << endl;
                exit(1);
            }
            matrix[i][j] = value;
        }
    }
    infile.close();
}

void Output() {
    Drawn();
    cout << "Truc X nam thang dung tu tren xuong duoi!\n";
    cout << "Truc Y nam ngang tu trai sang phai!\n";
    setColor(FOREGROUND_GREEN);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            cout << setw(5) << matrix[i][j];
        cout << endl;
    }
    resetColor();
    Drawn();
}

// Các hàm hỗ trợ
// Hàm kiểm tra xem một điểm có nằm trong mê cung không
bool isValid(int x, int y) {
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}

// Hàm nhập vào tọa độ xuất phát của robot
void enterStartingCoordinates(int& start_x, int& start_y) {
    do {
        setColor(FOREGROUND_GREEN);
        cout << "Nhap toa do xuat phat cua robot (x, y): ";
        resetColor();
        cin >> start_x >> start_y;
        if (!isValid(start_x, start_y)) {
            setColor(FOREGROUND_RED);
            cout << "Toa do khong hop le\n";
            resetColor();
        }
    } while (!isValid(start_x, start_y));
}

// Reset lại mảng visited
void resetVisited() {
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            visited[i][j] = false;
}

// So sánh 2 đường đi của 2 robot
void ComparePath(vector<point> path1, vector<point> path2) {
    set<int> res;
    for (int i = 0; i < path1.size(); ++i)
        for (int j = 0; j < path2.size(); ++j)
            if (path1[i].x == path2[j].x && path1[i].y == path2[j].y)
                res.insert(matrix[path1[i].x][path1[i].y]);
    setColor(FOREGROUND_GREEN);
    cout << "Nhung o 2 Robot di qua trung:\n";
    for (auto p : res)
        cout << p << ' ';
    cout << endl;
    resetColor();
}

// So sánh điểm của 2 robot
void CompareScore(int score1, int score2) {
    setColor(FOREGROUND_GREEN);
    if (score1 > score2) 
        cout << "Robot 1 co diem cao hon!" << endl;
    else if (score1 < score2) 
        cout << "Robot 2 co diem cao hon!" << endl;
    else 
        cout << "Hai robot co diem bang nhau!" << endl;
    resetColor();
}

// Sao chép đường đi của robot
vector<point> CopyMatrixPath() {
    vector<point> res;
    for (auto p : path)
        res.push_back(p);
    return res;
}

// Hàm đệ quy để tìm đường đi tốt nhất từ một vị trí (x, y)
int dfs(int x, int y) {
    visited[x][y] = true;
    path.push_back({ x, y }); // Thêm điểm (x, y) vào đường đi
    int max_value = 0;
    int next_x = -1, next_y = -1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny) && matrix[nx][ny] > max_value && !visited[nx][ny]) {
            max_value = matrix[nx][ny]; // Lưu lại giá trị lớn nhất
            next_x = nx;
            next_y = ny;
        }
    }
    if (max_value == 0) return 0; // Không còn điểm nào để đi, trả về 0
    return max_value + dfs(next_x, next_y); // Khi đã có giá trị tốt nhất tại điểm tiếp theo thì đi tiếp
}

// Các chế độ của robot
// Chế độ 1 robot
void RobotMode1() {
    int start_x, start_y;
    enterStartingCoordinates(start_x, start_y);
    cout << "----------------------------\n";
    ofstream outfile("output.txt");
    int max_score = dfs(start_x, start_y);
    setColor(FOREGROUND_BLUE);
    cout << "So luot di: " << path.size() << endl;
    cout << "Diem cao nhat ma robot co the dat duoc la: " << max_score << endl;
    cout << "Duong di cua robot la:\n";
    outfile << path.size() << endl;
    for (auto p : path) {
        cout << matrix[p.x][p.y];
        if (p.x != path.back().x || p.y != path.back().y) cout << " -> ";
        outfile << matrix[p.x][p.y] << " ";
    }
    cout << endl;
    resetColor();
    outfile.close();
    resetVisited();
    path.clear();
}

// Chế độ 2 robot
void RobotMode2_1() {
    int start_x1, start_y1, start_x2, start_y2;
    // Nhập vị trí xuất phát của robot 1
    cout << "Robot 1:\n";
    enterStartingCoordinates(start_x1, start_y1);

    // Tìm đường đi cho robot 1
    int max_score1 = dfs(start_x1, start_y1);
    vector<point> path1 = CopyMatrixPath();
    resetVisited();
    path.clear();

    // Nhập vị trí xuất phát của robot 2
    cout << "Robot 2:\n";
    enterStartingCoordinates(start_x2, start_y2);

    // Tìm đường đi cho robot 2
    int max_score2 = dfs(start_x2, start_y2);
    vector<point> path2 = CopyMatrixPath();
    resetVisited();
    path.clear();

    ofstream outfile("output.txt");
    // In thông tin và kết quả của robot 1
    cout << "----------------------------\n";
    setColor(FOREGROUND_BLUE);
    cout << "So luot di cua robot 1: " << path1.size() << endl;
    cout << "Diem cao nhat ma robot 1 co the dat duoc la: " << max_score1 << endl;
    cout << "Duong di cua robot 1 la:\n";
    outfile << "Robot 1:\n";
    outfile << path1.size() << endl;
    for (auto p : path1) {
        cout << matrix[p.x][p.y];
        if (p.x != path1.back().x || p.y != path1.back().y) cout << " -> ";
        outfile << matrix[p.x][p.y] << " ";
    }
    resetColor();
    cout << endl << "----------------------------\n";
    outfile << endl;

    // In thông tin và kết quả của robot 2
    setColor(FOREGROUND_BLUE);
    cout << "So luot di cua robot 2: " << path2.size() << endl;
    cout << "Diem cao nhat ma robot 2 co the dat duoc la: " << max_score2 << endl;
    cout << "Duong di cua robot 2 la:\n";
    outfile << "Robot 2:\n";
    outfile << path2.size() << endl;
    for (auto p : path2) {
        cout << matrix[p.x][p.y];
        if (p.x != path2.back().x || p.y != path2.back().y) cout << " -> ";
        outfile << matrix[p.x][p.y] << " ";
    }
    resetColor();
    cout << endl << "----------------------------\n";
    outfile << endl;
    outfile.close();

    // So sánh điểm của 2 robot và in ra kết quả
    CompareScore(max_score1, max_score2);
    ComparePath(path1, path2); // Đường đi chung của 2 robot
}

// Chế độ 2 robot thay phiên nhau đi và không được trùng
void RobotMode2_2() {
    int start_x1, start_y1, start_x2, start_y2;
    // Nhập vị trí xuất phát của robot 1
    cout << "Robot 1:\n";
    enterStartingCoordinates(start_x1, start_y1);

    // Nhập vị trí xuất phát của robot 2
    cout << "Robot 2:\n";
    do {
        setColor(FOREGROUND_GREEN);
        cout << "Nhap toa do xuat phat cua robot 2 (x, y): ";
        resetColor();
        cin >> start_x2 >> start_y2;
        if (!isValid(start_x2, start_y2)) {
            setColor(FOREGROUND_RED);
            cout << "Toa do khong hop le!\n";
            resetColor();
        }
        if (start_x1 == start_x2 && start_y1 == start_y2) {
            setColor(FOREGROUND_RED);
            cout << "Toa do cua 2 robot trung nhau!\n2 toa do robot nen khac nhau!\n";
            resetColor();
        }
    } while (!isValid(start_x2, start_y2) || (start_x1 == start_x2 && start_y1 == start_y2));

    // Tìm đường đi cho 2 robot
    visited[start_x1][start_y1] = true;
    visited[start_x2][start_y2] = true;
    vector<point> path1, path2;
    path1.push_back({ start_x1, start_y1 });
    path2.push_back({ start_x2, start_y2 });
    while (true) {
        int max_value1 = 0, max_value2 = 0;
        int next_x1 = -1, next_y1 = -1, next_x2 = -1, next_y2 = -1;
        // Robot 1 đi trước 
        for (int i = 0; i < 4; ++i) {
            int nx1 = start_x1 + dx[i];
            int ny1 = start_y1 + dy[i];
            if (isValid(nx1, ny1) && matrix[nx1][ny1] > max_value1 && !visited[nx1][ny1]) {
                max_value1 = matrix[nx1][ny1];
                next_x1 = nx1;
                next_y1 = ny1;
            }
        }
        if (max_value1 != 0) {
            start_x1 = next_x1;
            start_y1 = next_y1;
            visited[start_x1][start_y1] = true;
            path1.push_back({ start_x1, start_y1 });
        }
        // Robot 2 đi sau
        for (int i = 0; i < 4; ++i) {
            int nx2 = start_x2 + dx[i];
            int ny2 = start_y2 + dy[i];
            if (isValid(nx2, ny2) && matrix[nx2][ny2] > max_value2 && !visited[nx2][ny2]) {
                max_value2 = matrix[nx2][ny2];
                next_x2 = nx2;
                next_y2 = ny2;
            }
        }
        if (max_value2 != 0) {
            start_x2 = next_x2;
            start_y2 = next_y2;
            visited[start_x2][start_y2] = true;
            path2.push_back({ start_x2, start_y2 });
        }
        if (max_value1 == 0 && max_value2 == 0) break; // Không còn điểm nào để đi
    }
    resetVisited();

    // Tính tổng điểm của mỗi robot đi được
    int max_score1 = 0, max_score2 = 0;
    for (auto p : path1)
        max_score1 += matrix[p.x][p.y];
    for (auto p : path2)
        max_score2 += matrix[p.x][p.y];

    ofstream outfile("output.txt");
    // In thông tin và kết quả của robot 1
    cout << "----------------------------\n";
    setColor(FOREGROUND_BLUE);
    cout << "So luot di cua robot 1: " << path1.size() << endl;
    outfile << "Robot 1:\n" << path1.size() << endl;
    cout << "Diem cao nhat ma robot 1 co the dat duoc la: " << max_score1 << endl;
    cout << "Duong di cua robot 1 la:\n";
    for (auto p : path1) {
        cout << matrix[p.x][p.y];
        if (p.x != path1.back().x || p.y != path1.back().y) cout << " -> ";
        outfile << matrix[p.x][p.y] << " ";
    }
    resetColor();
    cout << endl << "----------------------------\n";
    outfile << endl;

    // In thông tin và kết quả của robot 2
    setColor(FOREGROUND_BLUE);
    cout << "So luot di cua robot 2: " << path2.size() << endl;
    outfile << "Robot 2:\n" << path2.size() << endl;
    cout << "Diem cao nhat ma robot 2 co the dat duoc la: " << max_score2 << endl;
    cout << "Duong di cua robot 2 la:\n";
    for (auto p : path2) {
        cout << matrix[p.x][p.y];
        if (p.x != path2.back().x || p.y != path2.back().y) cout << " -> ";
        outfile << matrix[p.x][p.y] << " ";
    }
    resetColor();
    cout << endl << "----------------------------\n";
    outfile.close();
    // So sánh điểm của 2 robot và in ra kết quả
    CompareScore(max_score1, max_score2);
}

int main() {
    InputFile();
    int choice;
    do {
        DrawnRobot();
        Output();
        setColor(FOREGROUND_RED);
        cout << "1. Chon che do 1 robot\n";
        cout << "2. Chon che do 2 robot\n";
        cout << "3. Chon che do 2 robot(moi con di 1 buoc va khong duoc trung)\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        resetColor();
        Drawn();
        switch (choice) {
        case 0:
            clearScreen();
            setColor(FOREGROUND_GREEN);
            cout << "Cam on ban da su dung chuong trinh\n";
            resetColor();
            break;
        case 1:
            RobotMode1();
            break;
        case 2:
            RobotMode2_1();
            break;
        case 3:
            RobotMode2_2();
            break;
        default:
            setColor(FOREGROUND_RED);
            cout << "Lua chon khong hop le\nMoi ban chon lai\n";
            resetColor();
            break;
        }
        cout << "Ban co muon chon lai khong? (1: Co, 0: Khong): ";
        cin >> choice;
        if (choice == 0) {
            clearScreen();
            setColor(FOREGROUND_GREEN);
            cout << "Cam on ban da su dung chuong trinh\n";
            resetColor();
        }
        else clearScreen();
    } while (choice != 0);
    matrix.clear();
    return 0;
}