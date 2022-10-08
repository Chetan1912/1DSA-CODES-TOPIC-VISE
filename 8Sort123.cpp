// this is not the actual code this is the aproatch in note book pg 14 problem
#include <bits/stdc++.h>
using namespace std;
// void sort012(int *arr, int n)

// {

//     int i = 0, j = 0, k = n - 1;

//     while (j <= k)
//     {

//         if (arr[j] == 0)
//         {

//             swap(arr[i], arr[j]);

//             i++;
//             j++;
//         }
//         else if (arr[j] == 1)
//         {

//             j++;
//         }
//         else
//         {

//        swap(arr[j], arr[k]);

//           k--;
//         }
//     }
// }
// or
void sort012(int *arr, int n)

{

    int begin = 0, end = n - 1;

    for (int i = 0; (i <= n) && (begin <= end); i++)
    {

        if (arr[begin] == 0)
        {

            swap(arr[i], arr[begin]);

            begin++;
        }
        else if (arr[begin] == 2)
        {
            swap(arr[begin], arr[end]);
            i--;
            end--;
        }
        else
        {
            begin++;
            i--;
        }
    }
}
int main()
{
    int arr[] = {2, 0, 2, 1, 0, 2, 0, 1, 1, 1, 1, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0};
    sort012(arr, 22);
    for (int i = 0; i < 22; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}