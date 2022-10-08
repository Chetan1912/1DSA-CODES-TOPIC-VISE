#include <iostream>
using namespace std;
int divide(int dividend, int divisor)
{
    int i = 0;
    int mod;
    int d1 = 0, d2 = 0;
    if (dividend > INT_MAX)
    {
        return INT_MAX;
    }
    if (dividend < INT_MIN)
    {
        return INT_MIN;
    }
    if (dividend < 0)
    {
        dividend = -dividend;
        d1 = 1;
    }
    if (divisor < 0)
    {
        divisor = -divisor;
        d2 = 1;
    }
    for (i = 0; dividend != 0 && dividend >= divisor; i++)
    {
        if (i == 0)
        {

            mod = dividend % divisor;
            dividend = dividend - mod;
        }
        dividend = dividend - divisor;
    }
    if ((d1 == 1 && d2 == 1) || (d1 == 0 && d2 == 0))
    {
        return i;
    }
    if ((d1 == 0 && d2 == 1) || (d1 == 1 && d2 == 0))
    {
        return -i;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    int d = divide(a, b);
    cout << d;
}