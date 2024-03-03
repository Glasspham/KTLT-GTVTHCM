#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << setfill('-') << setw(27) << "-" << endl;
    cout << setfill(' ');    
    cout << "| " << setw(3) << "Do" << " | " << setw(7) << " sin " << " | " << setw(7) << "cos " << " | "<< endl;
    cout << setfill('-') << setw(27) << "-" << endl;
    cout << setfill(' ');
    for (int i = 0; i <= 180; i += 5)
    {
        cout << "| " << setw(3) << i << " | " << setw(7) << fixed << setprecision(4) << sin(i) << " | " << setw(7) << cos(i) << setw(3) << " | " << endl;
        cout << setfill('-') << setw(27) << "-" << endl;
        cout << setfill(' '); 
    }    
    return 0;
}
