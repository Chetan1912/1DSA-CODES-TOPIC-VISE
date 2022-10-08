#include <iostream>
using namespace std;
int twopower(int n)
{
    if (n == 0)

    {
        return 1;
    }
    int fp = 2 * twopower(n - 1);
    return fp;
}
int main()
{
    int n;
    cout << "ENTER THE POWER OF 2" << endl;
    cin >> n;
    int pow = twopower(n);
    cout << pow;
}