#include<iostream>
using namespace std;
int main()
{
    int kWh;
    do
    {
        cout << "Nhap vao so kWh dien da sai: ";
        cin >> kWh;
        if(kWh < 0) cout << "Nhap sai! \n";
    } while (kWh < 0);
    
    int money;
    if(kWh <= 100)
        money = kWh * 550;
    else if(kWh <= 150)
        money = 100 * 550 + (kWh - 100) * 900;
    else if(kWh <= 200)
        money = 100 * 550 + 50 * 900 + (kWh - 150) * 1250;
    else if(kWh <= 300)
        money = 100 * 550 + 50 * 900 + 50 * 1250 + (kWh - 200) * 1450;
    else
        money = 100 * 550 + 50 * 900 + 50 * 1250 + 100 * 1450 + (kWh - 300) * 1700;

    money = (money * 110) / 100;
    cout << "So tien dien trong thang do la: " << money << endl;
    return 0;
}