#include <iostream>
using namespace std;
void saydigi(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    int deg = n % 10;
    n = n / 10;
    saydigi(n, arr);
    cout << arr[deg] << " ";
}
int main()
{
    string arr[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int n;
    cout << "ENTER THE DIGIT " << endl;
    cin >> n;
    saydigi(n, arr);
}