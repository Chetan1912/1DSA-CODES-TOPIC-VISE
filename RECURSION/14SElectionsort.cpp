
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void selectionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    int min = INT_MAX;
    int inx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            inx = i;
        }
    }

    swap(arr[0], arr[inx]);

    selectionSort(arr + 1, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    selectionSort(arr, n);

    cout << endl
         << "After sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}