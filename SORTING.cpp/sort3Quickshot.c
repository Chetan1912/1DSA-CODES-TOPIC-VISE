#include <stdio.h>
// should be always upperside
int partition(int ar[], int low, int high)
{
    int pivot = ar[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (ar[i] <= pivot)
        {
            i++;
        }
        while (ar[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {

            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
        }

    } while (i < j);

    temp = ar[low];
    ar[low] = ar[j];
    ar[j] = temp;
    return j;
}
void quickshot(int arr[], int low, int high)
{
    int PartitionIndex; // index of pivot after partition;
    if (low < high)
    {
        PartitionIndex = partition(arr, low, high);
        quickshot(arr, low, PartitionIndex - 1);  // sort left sub array
        quickshot(arr, PartitionIndex + 1, high); // sort right sub array
    }
}
int main()
{
    int arr[] = {90, 23, 101, 45, 65, 28, 67, 89, 34, 29};
    // print after the sort;
    quickshot(arr, 0, 9);
    // print

    for (int i = 0; i < 9; i++)
    {
        printf("%d,", arr[i]);
    }
} // by the love babbar
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)

    void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partitioon karenfe
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p - 1);

    // right wala part sort karo
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[10] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
    int n = 10;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
