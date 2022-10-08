//  724 leet code exein a array 1,2,5,8,9(sorted array)   --> 8,9,1,2,5 ; here the pivot is 1.;
// aproach --> complexity O(logn);
#include <iostream>
using namespace std;
int pivot(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s; // can also return the : e : because both are equal;
}
int main()
{
    int arr[] = {8, 9, 10, 12, 0, 1, 5, 8, 8};
    cout << "THE PIVOT ELLEMENT IS : " << pivot(arr, 7);
}

// the real solution of the leet code
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

//     If the index is on the left edge of the array,
//     then the left sum is 0 because there are no elements to the left.This also applies to the right edge of the array.

//     Return the leftmost pivot index.If no such index exists,
//     return -1.

// class Solution
// {
// public:
//     int pivotIndex(vector<int> &nums)
//     {

//         int total = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             total += nums[i];
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             int sum = 0;
//             for (int j = 0; j < i; j++)
//             {
//                 sum += nums[j];
//             }
//             int kp = total - sum - nums[i]; //because have to calculate the  sum after pivot
//             if (kp == sum)
//             {

//                 return i;
//             }
//         }

//         return -1;
//     }
// };