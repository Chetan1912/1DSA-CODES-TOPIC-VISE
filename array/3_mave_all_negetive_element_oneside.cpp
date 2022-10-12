Move all negative numbers to beginning and positive to end with constant extra space
    Difficulty Level : Easy
                           Last Updated : 14 Jun,
                       2022 Read
                           Discuss

                               An array contains both positive and negative numbers in random order.Rearrange the array elements so that all negative numbers appear before all positive numbers.

                       Examples :

    Input : -12,
                       11,
                       -13,
                       -5,
                       6,
                       -7,
                       5,
                       -3,
                       -6 Output : -12 - 13 - 5 - 7 - 3 - 6 11 6 5

                                                          Note : Order of elements is not important here.

                                                                 Recommended : Please try your approach on{IDE} first,
                       before moving on to the solution.Naive approach : The idea is to sort the array of elements,
                       this will make sure that all the negative elements will come before all the positive elements.Below is the implementation of the above approach :

#include <iostream>
#include <vector>
#include <algorithm>
    using namespace std;
void move(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}
int main()
{

    vector<int> arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    move(arr);
    for (int e : arr)
        cout << e << " ";
    return 0;
}

// This code is contributed by repakaeshwaripriya
Output - 7 - 3 - 1 2 4 5 6 8 9 Time Complexity : O(n *log(n)), Where n is the length of the given array.Auxiliary Space : O(n)

                                                                                                                              Efficient Approach 1 : The idea is to simply apply the partition process of quicksort.

// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
                                                                                                                                                     using namespace std;

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// A utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Driver code
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
Output - 1 - 3 - 7 4 5 6 2 8 9 Time complexity : O(N) Auxiliary Space : O(1)

                                                                            Two Pointer Approach : The idea is to solve this problem with constant space and linear time is by using a two
                                                                                                   -
                                                                                                   pointer
    or two - variable approach where we simply take two variables like left and right which hold the 0 and N - 1 indexes.Just need to check that :

    Check If the left and right pointer elements are negative then simply increment the left pointer.Otherwise,
    if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.Else if the left element is positive and the right element is also positive then simply decrement the right pointer.Repeat the above 3 steps until the left pointer ≤ right pointer.Below is the implementation of the above approach :

// C++ program of the above
// approach

#include <iostream>
    using namespace std;

// Function to shift all the
// negative elements on left side
void shiftall(int arr[], int left,
              int right)
{

    // Loop to iterate over the
    // array from left to the right
    while (left <= right)
    {
        // Condition to check if the left
        // and the right elements are
        // negative
        if (arr[left] < 0 && arr[right] < 0)
            left += 1;

        // Condition to check if the left
        // pointer element is positive and
        // the right pointer element is negative
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left += 1;
            right -= 1;
        }

        // Condition to check if both the
        // elements are positive
        else if (arr[left] > 0 && arr[right] > 0)
            right -= 1;
        else
        {
            left += 1;
            right -= 1;
        }
    }
}

// Function to print the array
void display(int arr[], int right)
{

    // Loop to iterate over the element
    // of the given array
    for (int i = 0; i <= right; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {-12, 11, -13, -5,
                 6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) /
                   sizeof(arr[0]);

    // Function Call
    shiftall(arr, 0, arr_size - 1);
    display(arr, arr_size - 1);
    return 0;
}

// added by Dhruv Goyal
Output
-12 -3 -13 -5 -7 6 5 11 11 
This is an in-place rearranging algorithm for arranging the positive and negative numbers where the order of elements is not maintained.
Time Complexity: O(N)
Auxiliary Space: O(1)

The problem becomes difficult if we need to maintain the order of elements. Please refer to Rearrange positive and negative numbers with constant extra space for details.

This article is contributed by Apoorva. If you like GeeksforGeeks and would like to contribute, you can also write an article using write.geeksforgeeks.org or mail your article to review-team@geeksforgeeks.org. See your article appearing on the GeeksforGeek’s main page and help other Geeks.

Approach 3:
Here, we will use the famous Dutch National Flag Algorithm for two “colors”. The first color will be for all negative integers and the second color will be for all positive integers. We will divide the array into three partitions with the help of two pointers, low and high. 

ar[1…low-1] negative integers
ar[low…high] unknown
ar[high+1…N] positive integers
Now, we explore the array with the help of low pointer, shrinking the unknown partition, and moving elements to their correct partition in the process. We do this until we have explored all the elements, and size of the unknown partition shrinks to zero.

Below is the implementation of the above approach:

#include <iostream>
using namespace std;

// Swap Function.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Using Dutch National Flag Algorithm.
void reArrange(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] < 0)
        {
            low++;
        }
        else if (arr[high] > 0)
        {
            high--;
        }
        else
        {
            swap(arr[low], arr[high]);
        }
    }
}
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Data
    int arr[] = {1, 2, -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    reArrange(arr, n);
    displayArray(arr, n);
    return 0;
}
Output - 9 - 8 - 4 - 5 - 6 - 7 3 2 2 2 1 3 2 1 Time complexity : O(N) Auxiliary Space : O(1)
