#include <iostream>
using namespace std;
int sumthearray(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return arr[0];
    }
    int sum = arr[0] + sumthearray(arr + 1, size - 1);
    return sum;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -11};
    int sum = sumthearray(arr, 10);
    cout << sum;
}