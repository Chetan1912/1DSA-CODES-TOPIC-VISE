#include <iostream>
using namespace std;
int main()
{
    int arr[] = {4, 2, 1, 3, 1}, ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = ans ^ arr[i];
        ans = ans ^ i;
    }
    cout << ans;
}