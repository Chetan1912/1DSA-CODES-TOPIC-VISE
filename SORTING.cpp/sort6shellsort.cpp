#include <iostream>
using namespace std;
void shellsort(int arr[], int n) // n is for the number of ellement
{
    int temp;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i + gap] > arr[i])
                {
                    break;
                }
                else
                {
                    temp = arr[i + gap];
                    arr[i + gap] = arr[i];
                    arr[i] = temp;
                    printf("faltu\n");
                }
            }
        }
    }
}

int main()
{
    int arr[] = {90, 5000, 23, 101, 45, 65, 28, 67, 89, 34, 29};
    // print after the sort;
    shellsort(arr, 11);
    // print

    for (int i = 0; i < 11; i++)
    {
        printf("%d,", arr[i]);
    }
}
