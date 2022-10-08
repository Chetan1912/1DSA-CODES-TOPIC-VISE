#include <iostream>
using namespace std;
int main()
{
    int arr[] = {36, 50, 24, 56, 36, 24, 42, 50, 42, 56, 5, 8};
    int Xor = 0, first = 0, second = 0;
    for (int i = 0; i < 12; i++)
    {
        Xor = Xor ^ arr[i];
    }
    int rset = Xor & ~(Xor - 1); // for right most set bit........ concept in DSA nots pg no ---> 10
    for (int i = 0; i < 12; i++)
    {
        if (rset & arr[i])
        {
            first = first ^ arr[i];
        }
        else
        {
            second = second ^ arr[i];
        }
    }
    cout << first << endl
         << second;
}