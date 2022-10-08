#include <stdio.h>
void mergeconquer(int arr[], int si, int mid, int ei)
{
    int merged[100];
    int idx1 = si;      // for the handeling left side of a array
    int idx2 = mid + 1; // for the handeling right side of a array
    int x = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[x++] = arr[idx1++];
        }
        else
        {
            merged[x++] = arr[idx2++];
        }
    }
    while (idx1 <= mid) // for the eliment if that is in mid and the other is completed;
    {
        merged[x++] = arr[idx1++];
    }
    while (idx2 <= ei)
    {
        merged[x++] = arr[idx2++];
    }
    for (int i = 0, j = si; i < x; i++, j++)
    {
        arr[j] = merged[i];
        printf("%d,", arr[j]); // thisss is for understand the working of these two function ;not part of a actual code ;
    }
    printf("\n");
}
void mergeshotdivide(int arr[], int si, int ei)
{
    static int i = 0, j = 0, k = 0;
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2;
    // printf("THE MERGESHOTdivide STARTED 1 --> %d\n", i++); // THISS IS USE D TO RECURSIVE UNDERSTANDING
    mergeshotdivide(arr, si, mid);
    // printf("%d,%d\n", si, ei);
    // printf("THE MERGESHOTdivide STARTED 2 --> %d\n", j++);
    mergeshotdivide(arr, mid + 1, ei);
    // printf("%d,%d\n", mid + 1, ei);

    // printf("THE MERGESHOTCONQUERS STARTED 3 --> %d\n", k++);
    mergeconquer(arr, si, mid, ei);
    printf("ended\n");
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    // print after the sort;
    mergeshotdivide(arr, 0, 7);
    // print

    for (int i = 0; i < 7; i++)
    {
        printf("%d,", arr[i]);
    }
}
