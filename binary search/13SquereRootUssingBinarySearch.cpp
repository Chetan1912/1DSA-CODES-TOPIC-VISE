#include <iostream>
using namespace std;
long long int WithOutDesimal(long long int n) // for the with out fraction part;
{
    int s = 0, e = n;
    long long int ans = 0;

    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        long long int sq = mid * mid;
        if (sq == n)
        {
            return mid;
        }
        else if (sq < n)
        {
            s = mid + 1; // this is for the condition which get false at one point
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
double PERFECT(long long int X, int aprox, int pos)
{
    double flag = 1;
    double ans = aprox;
    for (int i = 0; i < pos; i++)
    {

        flag = flag / 10;
        for (double j = ans; j * j <= X; j += flag)
        {
            ans = j;
            cout << i << " " << j << " " << ans << endl;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "PLEASE ENTER THE  NUMBER WHOSE SQUERE ROOT YOU WANT : ";
    cin >> n;
    int temp = WithOutDesimal(n);
    double as = PERFECT(n, temp, 7);
    cout << "THE SQUERE ROOT OF THE " << n << " IS " << as; // 4 is the position after desimal;
}