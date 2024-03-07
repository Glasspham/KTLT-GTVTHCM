#include<iostream>
#include<time.h>
#include<stdlib.h> 
using namespace std;
int main()
{
    srand(time(NULL));
    cout << "Tro choi doan so tu (1 den 100)!\n";
    int choice, n, x, m; 
    
    do
    {
        cout << "Co 2 che do:\n1. Ban chon so va may doan.\n2. Ban doan va may chon so.\n0. Ket thuc tro choi.\n";
        cout << "--------------------------------\n";
        cin >> choice;

        if(choice == 0) 
        {
            system("cls");
            cout << "Tro choi da ket thuc!\n";
        }

        if(choice < 0 || choice > 2)
        {
            system("cls");
            cout << "Moi ban chon lai!\n";
            cout << "--------------------------------\n";
        }
            
        if(choice == 1)
        {
            system("cls");
            cout << "Che do nguoi chon so, may doan!\n";

            do
            {
                cout << "Moi ban nhap vao so bat ki: ";
                cin >> x;
                if(x < 1 || x > 100) cout << "Nhap lai!\n";
            } while (x < 1 || x > 100);

            do
            {
                cout << "So lan duoc doan la: ";
                cin >> n;
                if(n < 0) cout << "Moi ban nhap lai!\n";
            } while (n < 0);
            cout << "--------------------------------\n";

            int l = 1,  r = 100;
            bool f = true;
            m = rand() % 100 + 1;

            for (int i = 1; i <= n; i++)
            {
                cout << i << ". Toi doan x la " << m << endl;
                int selection; 
                do
                {
                    cout << " 1.Dung roi!\n 2.Sai roi x nho hon!\n 3.Sai roi x lon hon!\n";
                    cout << "--------------------------------\n";
                    cout << "Hay cho toi biet ket qua: ";
                    cin >> selection;
                    if(selection < 1 || 3 < selection)
                        cout << "Moi ban chon lai!\n";
                } while(selection < 1 || 3 < selection);
                cout << "--------------------------------\n";

                if(selection == 1)
                {
                    system("cls");
                    cout << "Yeah! Toi da doan trung!\nBan co the tiep choi!\n";
                    cout << "--------------------------------\n";
                    f = false;
                    break;
                }

                else if(selection == 2)
                {
                    r = m - 1;
                    m = (l + r) / 2;
                }

                else if(selection == 3)
                {
                    l = m + 1;
                    m = (l + r) / 2;
                }
            }

            if(f)
            {
                system("cls");
                cout << "Toi da khong doan ra so cua ban!\nBan co the tiep choi!\n";
                cout << "--------------------------------\n";
            }
        }

        if(choice == 2)
        {
            system("cls");
            cout << "Che do ban doan va may chon so!\n";

            do
            {
                cout << "So lan duoc doan la: ";
                cin >> n;
                if(n < 0) cout << "Moi ban nhap lai!\n";
            } while (n < 0);
            cout << "--------------------------------\n";

            x = rand() % 100 + 1;
            bool f = true;

            for (int i = 1; i <= n; i++)
            {
                cout << i << ". Moi ban doan mot so bat ki: ";
                do
                {
                    cin >> m;
                    if(m < 1 || m > 100)
                        cout << "Moi nhap lai!\nMoi ban doan mot so bat ki: ";
                    
                } while (m < 1 || m > 100);
                
                if(m == x) 
                {
                    system("cls");
                    cout << "Chuc mung ban da doan trung!\nO lan thu " << i << "!\n";
                    cout << "Ban co the tiep tuc choi!\n";
                    cout << "--------------------------------\n";
                    f = false;
                    break;
                }

                else if(x > m) 
                    cout << "So x lon hon so ban nhap!\n";

                else cout << "So x nho hon so ban nhap!\n";
            }

            if(f) 
            {
                system("cls");
                cout << "Ban da that bai!\nSo x la " << x << endl;
                cout << "Ban co the tiep tuc choi!\n";
                cout << "--------------------------------\n";
            }
        }

    } while (choice != 0);
    return 0;
}
