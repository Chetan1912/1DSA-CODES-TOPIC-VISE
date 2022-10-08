#include <iostream>
using namespace std;
bool binarysearch(int arr[], int start, int end, int key)
{ // base case element not found
    if (start > end)
    {
        return 0;
    }
    int mid = start + (end - start) / 2;

    // element  found
    if (arr[mid] == key)
    {
        return 1;
    }

    if (arr[mid] < key)
    {
        return binarysearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarysearch(arr, start, mid - 1, key);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool found = binarysearch(arr, 0, 9, 10);
    cout << found;
}