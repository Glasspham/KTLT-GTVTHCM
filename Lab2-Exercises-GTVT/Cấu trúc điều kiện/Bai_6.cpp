#include<iostream>
#include<math.h>
using namespace std;

bool NamNhuan(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

int Day(int month, int year)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 2:
        if(NamNhuan(year))
            return 29;
        return 28; 
    default:
        return 30;
    }
}

void DayBefor(int day, int month, int year)
{
    day -= 1;
    if(day == 0)
    {
        month -= 1;
        if(month == 0)
        {
            month = 12;
            year -= 1;
        }
        day = Day(month, year);
    }
    cout << day << '/' << month << '/' << year << endl;
}

void DayAfter(int day, int month, int year)
{
    day += 1;
    if(day > Day(month, year))
    {
        day = 1;
        month += 1;
        if(month > 12)
        {
            month = 1;
            year += 1;
        }
    }
    cout << day << '/' << month << '/' << year << endl;
}

int main()
{
    int day, month, year;
    do
    {
        cout << "Nhap vao ngay thang nam (Cach nhau boi dau cach): ";
        cin >> day >> month >> year;
        if(year < 0)
            cout << "Da nhap sai nam! \n";
        if(month < 1 || month > 12)
            cout << "Da nhap sai thang! \n";
        if(day < 0 || day > Day(month, year))
            cout << "Da nhap sai ngay! \n";
        else 
        {
            cout << "Nhap dung! \n";
            break;
        }
    } while (year < 0 || (month < 1 || month > 12) || (day < 0 || day > Day(month, year)));

    if(month < 4) cout << "Quy 1! \n";
    else if(month < 7) cout << "Quy 2! \n";
    else if(month < 10) cout << "Quy 3! \n";
    else cout << "Quy 4! \n";

    cout << "Thang nhap vao co " << Day(month, year) << " ngay \n";
    
    DayBefor(day, month, year);
    DayAfter(day, month, year);
    return 0;
}