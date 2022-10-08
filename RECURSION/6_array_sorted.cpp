#include <iostream>
using namespace std;
bool issorted(int arr[], int size)
{
    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool st = issorted(arr + 1, size - 1);
        return st;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    bool st = issorted(arr, 5);
    cout << st;
}