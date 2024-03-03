#include<iostream>
#include<vector>
using namespace std;
#if 0
int main()
{
    vector<float> a;
    float num;
    while (cin >> num)
    {
        if(num == 9999)
            break;
        a.push_back(num);      
    }
    float sum = 0;
    for(int i : a) 
        sum += i;
    cout << "Trung binh cong day so tren la: " << sum / a.size() << endl;
    return 0;
}
#endif

#if 1
int main()
{
    float sum = 0;
    int cnt = 0;
    float num;
    while (cin >> num)
    {
        if(num == 9999)
            break;
        sum += num;
        ++cnt;
    }
    cout << "Trung binh cong day so tren la: " << sum / cnt << endl;
    return 0;
}
#endif