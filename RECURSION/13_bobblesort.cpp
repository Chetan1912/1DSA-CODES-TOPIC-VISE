#include <iostream>
using namespace std;
void bubblesort(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    // first case
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    // sort all before last
    bubblesort(arr, size - 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6555, 722, 8, 9, -11};
    bubblesort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}