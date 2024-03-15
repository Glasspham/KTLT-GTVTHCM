#include <iostream>
#include <string>
using namespace std;
#if 0
void convertAndDisplay(long long int num, int base) 
{
    string result = "";
    while (num > 0) 
    {
        int digit = num % base;
        char digitChar;
        if (digit < 10)
            digitChar = digit + '0';
        else // Này là trường hợp của hệ 16 mới có biến kí tự bên trong
            digitChar = digit - 10 + 'A';
        result = digitChar + result;
        num /= base;
    }
    cout << "Base " << base << ": " << result << endl;
}

int main() 
{
    long long int num;
    do
    {
        cout << "Nhap vao mot so nguyen bat ki: ";
        cin >> num;
        if(num < 0) cout << "Nhap lai!\n";
    } while (num < 0);
    
    convertAndDisplay(num, 10);
    convertAndDisplay(num, 16);
    convertAndDisplay(num, 8);
    convertAndDisplay(num, 2);
    return 0;
}
#endif

#if 1
int main()
{
    long long int num;
    do
    {
        cout << "Nhap vao mot so nguyen bat ki: ";
        cin >> num;
        if(num < 0) cout << "Nhap lai!\n";
    } while (num < 0);

    // Hệ số 10
    cout << "Base 10: " << num << endl;

    // Hệ số 16
    int tmp16 = num;
    string result16 = "";
    while (tmp16 > 0) 
    {
        int digit = tmp16 % 16;
        char digitChar;
        if (digit < 10)
            digitChar = digit + '0';
        else // Này là trường hợp của hệ 16 mới có biến kí tự bên trong
            digitChar = digit - 10 + 'A';
        result16 = digitChar + result16;
        tmp16 /= 16;
    } 
    cout << "Base 16: " << result16 << endl;

    // Hệ số 8
    int tmp8 = num;
    string result8 = "";
    while (tmp8 > 0) 
    {
        int digit = tmp8 % 8;
        char digitChar;
        digitChar = digit + '0';
        result8 = digitChar + result8;
        tmp8 /= 8;
    } 
    cout << "Base 8: " << result8 << endl;

    int tmp2 = num;
    string result2 = "";
    while (tmp2 > 0) 
    {
        int digit = tmp2 % 2;
        char digitChar;
        digitChar = digit + '0';
        result2 = digitChar + result2;
        tmp2 /= 2;
    } 
    cout << "Base 2: " << result2 << endl;
}
#endif
