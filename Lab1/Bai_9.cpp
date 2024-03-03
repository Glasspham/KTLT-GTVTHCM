#include<iostream>
using namespace std;
int main()
{
    int choice;
    do
    {
        int N; 
        do
        {
            cout << "Nhap con so co 2 chu so tro len(so duong): ";
            cin >> N;
            if(N < 10) cout << "Nhap sai! \n";
        } while (N < 10);
        int sum(0);
        while (N != 0)
        {
            sum += N % 10;
            N /= 10;
        }
        cout << sum << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
