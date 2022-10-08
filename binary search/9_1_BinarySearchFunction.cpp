#include <iostream>
using namespace std;
int binarysearch(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 5, 8, 10, 50, 100, 500, 550, 1000}, n;
    cout << "ENTER THE ELLEMENT TO BE SEARCHED : ";
    cin >> n;
    cout << "THE POSISION OF " << n << " is " << binarysearch(arr, 9, n);
}