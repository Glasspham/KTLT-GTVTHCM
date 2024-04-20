#include <iostream> 
#include <fstream> 
#include <Windows.h> 
#include <iomanip> 
#include <string>
using namespace std;

const int ROW = 6;
const int COL = 5;
int matrix[ROW][COL];

struct MaxValue{
    int max_value; // lấy giá trị lớn nhất của các số xung quanh 
    int col;       // vị trí cột 
    int row;       // vị trí dòng 
} strMaxValue;     // lưu các giá trị của struct 

int max_path[ROW * COL]; // Mảng lưu trữ đường đi lớn nhất 
int path_index = 0;      // Chỉ số của mảng max_path, theo dõi vị trí hiện tại của mảng max_path 

// set màu cho chữ 
void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void clearScreen(){
    system("cls");
}

// kiểm tra item có tồn tại trong đường đi chưa 
bool check(int itemToFind){
    for (int i = 0; i < path_index; i++)
        if (max_path[i] == itemToFind)
            return true;
    return false;
}

// tìm số lớn nhất trong mảng 
int find_max(int arr[], int size){
    int max_value = -1; // Giá trị lớn nhất ban đầu là phần tử đầu tiên của mảng 
    for (int i = 0; i < size; i++){
        // Kiểm tra item cần check có trong mảng chưa, có thì bỏ qua 
        if (check(arr[i]))
            continue;
        if (arr[i] > max_value)
            max_value = arr[i];
    }
    return max_value;
}

//hàm trả về giá trị lớn nhất của các phần tử xung quanh robot 
void find_max_matrix(int row, int col){
    // Góc trên trái 
    if (row == 0 && col == 0){
        int arr[2] = { matrix[row][col + 1], matrix[row + 1][col] };
        strMaxValue.max_value = find_max(arr, 2);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col + 1;
            strMaxValue.row = row;
        }

        if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col;
            strMaxValue.row = row + 1;
        }
    }

    // Góc dưới phải 
    else if (row == ROW - 1 && col == 0){
        int arr[2] = { matrix[row - 1][0], matrix[row][col + 1] };
        strMaxValue.max_value = find_max(arr, 2);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = 0;
            strMaxValue.row = row - 1;
        }

        if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col + 1;
            strMaxValue.row = row;
        }
    }

    // Góc dưới trái 
    else if (row == ROW - 1 && col == COL - 1){
        int arr[2] = { matrix[row - 1][col], matrix[row][col - 1] };
        strMaxValue.max_value = find_max(arr, 2);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col;
            strMaxValue.row = row - 1;
        }
        
        if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col - 1;
            strMaxValue.row = row;
        }
    }

    // góc trên phải 
    else if (row == 0 && col == COL - 1){
        int arr[2] = { matrix[0][col - 1], matrix[row + 1][col] };
        strMaxValue.max_value = find_max(arr, 2);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col - 1;
            strMaxValue.row = 0;
        }

        if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col;
            strMaxValue.row = row + 1;
        }
    }

    // biên trên 
    else if (row == 0){
        int arr[3] = { matrix[0][col - 1], matrix[0][col + 1], matrix[row + 1][col] };
        strMaxValue.max_value = find_max(arr, 3);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col - 1;
            strMaxValue.row = 0;
        }

        else if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col + 1;
            strMaxValue.row = 0;
        }

        else{
            strMaxValue.col = col;
            strMaxValue.row = row + 1;
        }
    }

    // biên dưới 
    else if (row == ROW - 1){
        int arr[3] = { matrix[row][col - 1], matrix[row][col + 1], matrix[row - 1][col] };
        strMaxValue.max_value = find_max(arr, 3);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col - 1;
            strMaxValue.row = row;
        }

        else if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col + 1;
            strMaxValue.row = row;
        }

        else{
            strMaxValue.col = col;
            strMaxValue.row = row - 1;
        }
    }

    // biên trái 
    else if (col == 0){
        int arr[3] = { matrix[row - 1][0], matrix[row + 1][0], matrix[row][col + 1] };
        strMaxValue.max_value = find_max(arr, 3);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = 0;
            strMaxValue.row = row - 1;
        }

        else if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = 0;
            strMaxValue.row = row + 1;
        }

        else{
            strMaxValue.col = col + 1;
            strMaxValue.row = row;
        }
    }

    // biên phải 
    else if (col == COL - 1){
        int arr[3] = { matrix[row - 1][col], matrix[row + 1][col], matrix[row][col - 1] };
        strMaxValue.max_value = find_max(arr, 3);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col;
            strMaxValue.row = row - 1;
        }

        else if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col;
            strMaxValue.row = row + 1;
        }

        else{
            strMaxValue.col = col - 1;
            strMaxValue.row = row;
        }
    }

    // Vị trí trung tâm (4 hướng) 
    else{
        int arr[4] = { matrix[row][col - 1], matrix[row][col + 1], matrix[row - 1][col], matrix[row + 1][col] };
        strMaxValue.max_value = find_max(arr, 4);

        // Lấy vị trí của max value 
        if (arr[0] == strMaxValue.max_value){
            strMaxValue.col = col - 1;
            strMaxValue.row = row;
        }

        else if (arr[1] == strMaxValue.max_value){
            strMaxValue.col = col + 1;
            strMaxValue.row = row;
        }

        else if (arr[2] == strMaxValue.max_value){
            strMaxValue.col = col;
            strMaxValue.row = row - 1;
        }

        else{
            strMaxValue.col = col;
            strMaxValue.row = row + 1;
        }
    }
}

// Hàm đệ quy tìm kiếm đường đi lớn nhất 
void find_max_path(int row, int col, int current_value){
    // Lưu giá trị hiện tại vào mảng max_path 
    max_path[path_index++] = current_value;
    find_max_matrix(row, col);
    if (strMaxValue.max_value == -1)
        return;
    find_max_path(strMaxValue.row, strMaxValue.col, matrix[strMaxValue.row][strMaxValue.col]);
}

// Hàm tìm đường trùng nhau của robot  
void find_diff(int row1, int col1, int row2, int col2){
    int str_value = matrix[row1][col1];
    find_max_path(row1, col1, str_value);
    int* max_a = new int[path_index];
    int pax1 = path_index;
    for (int i = 0; i < pax1; i++)
        max_a[i] = max_path[i];
    cout << endl;
    path_index = 0;
    int str_value2 = matrix[row2][col2];
    find_max_path(row2, col2, str_value2);
    int* max_b = new int[path_index];
    int pax2 = path_index;
    for (int j = 0; j < pax2; j++)
        max_b[j] = max_path[j];
    ofstream outputFile("output.txt", ios_base::app);
    outputFile << "Cac vi tri 2 ROBOT di trung: ";
    setColor(FOREGROUND_RED);
    cout << "Cac vi tri 2 ROBOT di trung: ";
    resetColor();
    for (int i = 0; i < pax1; i++)
        for (int j = 0; j < pax2; j++)
            if (max_a[i] == max_b[j]){
                outputFile << max_a[i] << " ";
                cout << max_a[i] << " ";
                break;
            }
    outputFile.close();
    delete[] max_a;
    delete[] max_b;
}

void xuat(int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            setColor(FOREGROUND_GREEN);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    resetColor();
}

// Vẽ robot
void Robot(){
    setColor(FOREGROUND_GREEN);
    cout << setw(75) << "   " << "-----" << "   " << endl;
    cout << setw(76) << "  | " << "o o" << " |  " << endl;
    cout << setw(77) << "  |  " << "^" << "  |  " << endl;
    cout << setw(76) << "  | " << "\\_/" << " |  " << endl;
    cout << setw(75) << "   " << "-----" << "   " << endl;
    cout << setw(83) << "     |     " << endl;
    cout << setw(83) << "    / \\    " << endl;
    resetColor();
}

void Robot1(){
    cout << "====================================================================";
    setColor(FOREGROUND_RED);
    cout << "GAME ROBOT TIM DUONG";
    resetColor();
    cout << "====================================================================" << endl << endl;
    Robot();
    cout << endl << "============================================================================================================================================================" << endl;
    setColor(FOREGROUND_BLUE);
    cout << setw(82) << "Chon che do choi" << endl;
    resetColor();
    cout << setw(79) << "1: 1 ROBOT" << endl << setw(79) << "2: 2 ROBOT" << endl << setw(82) << "3: ROBOT TURN" << endl << setw(82) << "0: Ket Thuc !" << endl;
}

int main(){
    //nhap du lieu tu file input.txt vao ma tran 
    ifstream input("input.txt");
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            input >> matrix[i][j];
    input.close();
    ofstream outputFile("output.txt");
    int r = ROW;
    int c = COL;
    Robot1();
pow1:
    int n;
    cout << setw(68) << "Chon: "; cin >> n;
    cout << endl;
    if (n == 1){
        cout << "===================================" << endl;
        xuat(r, c);
        cout << "===================================" << endl << endl;
    a1:
        path_index = 0;
        int start_row, start_col;
        setColor(FOREGROUND_BLUE);
        cout << "Nhap vi tri bat dau (ROWS,COL): " << endl;
        resetColor();
        cout << "--------> ROWS: ";
        cin >> start_row;
        cout << "--------> COL: ";
        cin >> start_col;
        cout << "===============================" << endl;
        int start_value = matrix[start_row][start_col];
        if (start_row > 6 || start_col > 5){
            setColor(FOREGROUND_RED);
            cout << "Vuot qua gioi han ma tran (6*5), 0 diem :(" << endl;
            resetColor();
        }
        find_max_path(start_row, start_col, start_value);
        setColor(FOREGROUND_RED);
        cout << "Duong di: ";
        resetColor();
        outputFile << "Quang duong da di cua ROBOT: " << path_index << endl;
        outputFile << "Duong di : ";
        int sum = 0;
        for (int i = 0; i < path_index; i++){
            outputFile << max_path[i] << " ";
            cout << max_path[i];
            if (i < path_index - 1){
                setColor(FOREGROUND_GREEN);
                cout << " --> ";
                resetColor();
            }
            sum += max_path[i];
        }
        cout << endl;
        setColor(FOREGROUND_RED);
        cout << "Quang duong ROBOT di chuyen: ";
        resetColor();
        cout << path_index << endl;
        outputFile << endl;
        outputFile << "So diem cua ROBOT:  ";
        setColor(FOREGROUND_GREEN);
        cout << "So diem cua ROBOT: ";
        resetColor();
        cout << sum;
        cout << endl;
        cout << "---------------------" << endl;
        outputFile << sum;
        outputFile << endl;
        outputFile << "=======================================================================================" << endl;
    o1:
        setColor(FOREGROUND_BLUE);
        cout << "Ban co muon choi tiep ?" << endl;
        resetColor();
        setColor(FOREGROUND_GREEN);
        cout << "1.Choi tiep" << endl;
        resetColor();
        setColor(FOREGROUND_RED);
        cout << "2.Ket thuc" << endl;
        resetColor();
        cout << "Chon: ";
        int p;
        cin >> p;
        cout << "====================" << endl;
        if (p == 1){
            int l;
        p1:
            clearScreen();
            Robot1();
            cout << setw(68) << "Chon: "; cin >> l;
            cout << endl;
            cout << "===================================" << endl;
            xuat(r, c);
            cout << "===================================" << endl << endl;
            if (l == 1)
                goto a1;
            else if (l == 2)
                goto a2;
            else if (l == 3)
                goto a3;
            else{
                cout << "Moi chon lai !" << endl;
                goto p1;
            }
        }
        else if (p == 2){
            setColor(FOREGROUND_GREEN);
            cout << "Thank you for playing the game ^_^" << endl;
            resetColor();
        }
        else{
            cout << "Moi ban chon lai !!!" << endl;
            cout << "-------------" << endl;
            goto o1;
        }
    }
    else if (n == 2){
        cout << "===================================" << endl;
        xuat(r, c);
        cout << "===================================" << endl << endl;
    a2:
        path_index = 0;
        int sum1 = 0, sum2 = 0;
        int start_row1, start_col1;
        setColor(FOREGROUND_BLUE);
        cout << "Nhap vi tri ROBOT 1 (ROWS,COL): " << endl;
        resetColor();
        cout << "--------> ROWS 1: ";
        cin >> start_row1;
        cout << "--------> COL 1: ";
        cin >> start_col1;
        int start_value1 = matrix[start_row1][start_col1];
        if (start_row1 > 6 || start_col1 > 5){
            setColor(FOREGROUND_RED);
            cout << "Vuot qua gioi han ma tran (6*5), 0 diem :(" << endl;
            resetColor();
        }
        cout << "===============================" << endl;
        find_max_path(start_row1, start_col1, start_value1);
        setColor(FOREGROUND_RED);
        cout << "Duong di: ";
        resetColor();
        outputFile << "Quang duong di cua ROBOT 1: " << path_index << endl;
        outputFile << "Duong di: ";
        for (int i = 0; i < path_index; i++){
            outputFile << max_path[i] << " ";
            cout << max_path[i];
            if (i < path_index - 1){
                setColor(FOREGROUND_GREEN);
                cout << " --> ";
                resetColor();
            }
            sum1 += max_path[i];
        }
        cout << endl;
        setColor(FOREGROUND_RED);
        cout << "Quang duong ROBOT 1 di chuyen : ";
        resetColor();
        cout << path_index << endl;
        setColor(FOREGROUND_GREEN);
        cout << "So diem ROBOT 1: ";
        resetColor();
        cout << sum1 << endl;
        cout << "===================" << endl;
        outputFile << endl;
        int t = path_index;
        path_index = 0;
        int start_row2, start_col2;
        setColor(FOREGROUND_BLUE);
        cout << "Nhap vi tri ROBOT 2 (ROWS,COL): " << endl;
        resetColor();
        cout << "--------> ROWS 2: ";
        cin >> start_row2;
        cout << "--------> COL 2: ";
        cin >> start_col2;
        int start_value2 = matrix[start_row2][start_col2];
        if (start_row2 > 6 || start_col2 > 5){
            setColor(FOREGROUND_RED);
            cout << "Vuot qua gioi han ma tran (6*5), 0 diem :(" << endl;
            resetColor();
        }
        cout << "===============================" << endl;
        find_max_path(start_row2, start_col2, start_value2);
        outputFile << "Quang duong di cua ROBOT 2: " << path_index << endl;
        setColor(FOREGROUND_RED);
        cout << "Duong di: ";
        resetColor();
        outputFile << "Duong di: ";
        for (int i = 0; i < path_index; i++){
            outputFile << max_path[i] << " ";
            cout << max_path[i] << " ";
            if (i < path_index - 1){
                setColor(FOREGROUND_GREEN);
                cout << " --> ";
                resetColor();
            }
            sum2 += max_path[i];
        }
        cout << endl;
        setColor(FOREGROUND_RED);
        cout << "Quang duong ROBOT 2 di chuyen : ";
        resetColor();
        cout << path_index << endl;
        setColor(FOREGROUND_GREEN);
        cout << "So diem ROBOT 2: ";
        resetColor();
        cout << sum2 << endl;
        cout << "==================" << endl;
        outputFile << endl;
        outputFile << "--------------------" << endl;
        setColor(FOREGROUND_RED);
        if (sum1 > sum2){
            cout << "ROBOT 1 Thang !!!" << endl;
            outputFile << "ROBOT 1 Thang !!!" << endl;
        }
        else{
            cout << "ROBOT 2 Thang !!!" << endl;
            outputFile << "ROBOT 2 Thang !!!" << endl;
        }
        resetColor();
        int t1 = path_index;
        path_index = 0;
        cout << "-----------------" << endl;
        outputFile << "--------------------" << endl;
        find_diff(start_row1, start_col1, start_row2, start_col2);
        cout << endl;
        cout << "------------------------" << endl;
        outputFile << "=======================================================================================" << endl;
    o2:
        setColor(FOREGROUND_BLUE);
        cout << "Ban co muon choi tiep ?" << endl;
        resetColor();
        setColor(FOREGROUND_GREEN);
        cout << "1.Choi tiep" << endl;
        resetColor();
        setColor(FOREGROUND_RED);
        cout << "2.Ket thuc" << endl;
        resetColor();
        cout << "Chon: ";
        int p;
        cin >> p;
        cout << "====================" << endl;
        if (p == 1){
            int l;
        p2:
            clearScreen();
            Robot1();
            cout << setw(68) << "Chon: "; cin >> l;
            cout << endl;
            cout << "===================================" << endl;
            xuat(r, c);
            cout << "===================================" << endl << endl;
            if (l == 1)
                goto a1;
            else if (l == 2)
                goto a2;
            else if (l == 3)
                goto a3;
            else{
                cout << "Moi chon lai !" << endl;
                goto p2;
            }
        }
        else if (p == 2){
            setColor(FOREGROUND_GREEN);
            cout << "Thank you for playing the game ^_^" << endl;
            resetColor();
        }
        else{
            cout << "Moi ban chon lai !!!" << endl;
            cout << "-------------" << endl;
            goto o2;
        }
    }
    else if (n == 3){
        xuat(r, c);
        cout << "================================" << endl;
    a3:
        path_index = 0;
        int sum3 = 0, sum4 = 0;
        int path3 = 0;
        int path4 = 0;
        int start_row3, start_col3;
        setColor(FOREGROUND_BLUE);
        cout << "Nhap vi tri ROBOT 1 (ROWS,COL): " << endl;
        resetColor();
        cout << "--------> ROWS 1: ";
        cin >> start_row3;
        cout << "--------> COL 1: ";
        cin >> start_col3;
        int start_value3 = matrix[start_row3][start_col3];
        if (start_row3 > 6 || start_col3 > 5){
            setColor(FOREGROUND_RED);
            cout << "Vuot qua gioi han ma tran (6*5), 0 diem :(" << endl;
            resetColor();
        }
        cout << "===============================" << endl;
        find_max_path(start_row3, start_col3, start_value3);
        setColor(FOREGROUND_RED);
        outputFile << "Duong di cua ROBOT 1: ";
        cout << "Duong di cua ROBOT 1: ";
        resetColor();
        for (int i = 0; i < path_index; i++){
            outputFile << max_path[i] << " ";
            cout << max_path[i];
            if (i < path_index - 1){
                setColor(FOREGROUND_GREEN);
                cout << " --> ";
                resetColor();
            }
            sum3 += max_path[i];
            path3++;
        }
        outputFile << endl;
        cout << endl;
        setColor(FOREGROUND_RED);
        cout << "Quang duong ROBOT 1 di chuyen : ";
        resetColor();
        cout << path3 << endl;
        setColor(FOREGROUND_GREEN);
        cout << "So diem cua ROBOT 1: ";
        resetColor();
        cout << sum3 << endl;
        outputFile << "Quang duong di duoc: " << path3 << endl;
        outputFile << "So diem ghi duoc: " << sum3 << endl;
        int t3 = path_index;
        cout << "=======================" << endl;
        int start_row4, start_col4;
        setColor(FOREGROUND_BLUE);
        cout << "Nhap vi tri ROBOT 2 (ROWS,COL): " << endl;
        resetColor();
        cout << "--------> ROWS 2: ";
        cin >> start_row4;
        cout << "--------> COL 2: ";
        cin >> start_col4;
        int start_value4 = matrix[start_row4][start_col4];
        if (start_row4 > 6 || start_col4 > 5){
            setColor(FOREGROUND_RED);
            cout << "Vuot qua gioi han ma tran (6*5), 0 diem :(" << endl;
            resetColor();
        }
        cout << "===============================" << endl;
        outputFile << endl;
        outputFile << "-------------------------" << endl;
        find_max_path(start_row4, start_col4, start_value4);
        outputFile << "Duong di cua ROBOT 2: ";
        setColor(FOREGROUND_RED);
        cout << "Duong di cua ROBOT 2: ";
        resetColor();
        for (int i = t3; i < path_index; i++){
            outputFile << max_path[i] << " ";
            cout << max_path[i];
            if (i < path_index - 1){
                setColor(FOREGROUND_GREEN);
                cout << " --> ";
                resetColor();
            }
            sum4 += max_path[i];
            path4++;
        }
        cout << endl;
        outputFile << endl;
        outputFile << "Quang duong di duoc: " << path4 << endl;
        setColor(FOREGROUND_RED);
        cout << "Quang duong di duoc: ";
        resetColor();
        cout << path4 << endl;
        setColor(FOREGROUND_GREEN);
        cout << "So diem ghi duoc: ";
        resetColor();
        cout << sum4 << endl;
        outputFile << "So diem ghi duoc: " << sum4 << endl;
        outputFile << endl;
        cout << endl;
        outputFile << "-------------------------" << endl;
        cout << "=======================" << endl;
        setColor(FOREGROUND_GREEN);
        if (sum3 > sum4){
            cout << "ROBOT 1 Thang !!!" << endl;
            outputFile << "ROBOT 1 thang !!!" << endl;
        }
        else{
            outputFile << "ROBOT 2 thang !!!" << endl;
            cout << "ROBOT 2 Thang !!!" << endl;
        }
        resetColor();
        cout << "=======================" << endl;
        outputFile << "=======================================================================================" << endl;
    o3:
        setColor(FOREGROUND_BLUE);
        cout << "Ban co muon choi tiep ?" << endl;
        resetColor();
        setColor(FOREGROUND_GREEN);
        cout << "1.Choi tiep" << endl;
        resetColor();
        setColor(FOREGROUND_RED);
        cout << "2.Ket thuc" << endl;
        resetColor();
        int p;
        cout << "Chon: ";
        cin >> p;
        cout << "====================" << endl;
        if (p == 1){
            int l;
        p3:
            clearScreen();
            Robot1();
            cout << setw(68) << "Chon: "; cin >> l;
            cout << endl;
            cout << "===================================" << endl;
            xuat(r, c);
            cout << "===================================" << endl << endl;
            if (l == 1)
                goto a1;
            else if (l == 2)
                goto a2;
            else if (l == 3)
                goto a3;
            else{
                cout << "Moi chon lai !" << endl;
                goto p3;
            }
        }
        else if (p == 2){
            setColor(FOREGROUND_GREEN);
            cout << "Thank you for playing the game ^_^" << endl;
            resetColor();
        }
        else{
            cout << "Moi ban chon lai !!!" << endl;
            cout << "-------------" << endl;
            goto o3;
        }
    }
    else if (n == 0)
        cout << "Hen gap lai ^_^" << endl;
    else{
        setColor(FOREGROUND_RED);
        cout << "MOI BAN NHAP LAI *_*" << endl;
        resetColor();
        goto pow1;
    }
    outputFile.close();
    cout << "=========================" << endl << "Ket qua da duoc ghi vao file ! " << endl;
    return 0;
}