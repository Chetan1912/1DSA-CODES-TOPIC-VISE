#include <iostream>
using namespace std;
double multiply(double num, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * num;
    }
    return ans;
}
double nthroot(int n, int m)
{
    double s = 0, e = m;
    double eps = 1e-7; //--> 10^(-6)
    while ((e - s) > eps)

    {
        cout << s << " " << e << endl; // for see process
        double mid = s + (e - s) / 2.0;
        if (multiply(mid, n) < m)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    cout << s << " " << e;
}
int main()
{
    int n, m;
    cout << "enter the number : ";
    cin >> m;
    cout << "enter the value of n :";
    cin >> n;
    // m is number

    nthroot(n, m);
}