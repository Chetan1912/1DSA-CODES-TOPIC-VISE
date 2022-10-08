#include <iostream>
using namespace std;
#include <math.h>
int main()
{

    long long int n;
    cout << "please enter the binary no" << endl;
    cin >> n;

    long long int desimal = 0, digit;
    int i = 0;
    while (n != 0)
    {
        digit = n % 10;
        if (digit == 1)
        {
            desimal = desimal + pow(2, i);
        }
        n = n / 10;
        i++;
    }
    cout << "desimal = " << desimal;
}