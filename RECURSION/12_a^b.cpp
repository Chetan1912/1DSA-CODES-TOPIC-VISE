#include <iostream>
using namespace std;
int power(int a, int b)
{
    // cout << a << " " << b << endl;
    if (b == 0)
    {
        return 1;
    }
    if (b & 1)
    {
        return a * power(a * a, b / 2);
    }
    else
    {
        return power(a * a, b / 2);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    int pow = power(a, b);
    cout << pow;
}