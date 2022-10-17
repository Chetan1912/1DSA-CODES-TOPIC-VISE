/*
Sum of minimum and maximum elements of all subarrays of size k.
Difficulty Level : Hard
Last Updated : 04 Sep, 2022
Read
Discuss

Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

Examples:

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}
        K = 4
Output : 18
Explanation : Subarrays of size 4 are :
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4

     Missing sub arrays -

     {2, -1, 7, -3}
     {2, 7, -3, -1}
     {2, -3, -1, -2}
     {5, 7, -3, -1}
     {5, -3, -1, -2}
     and few more -- why these were not considered??
     Considering missing arrays result coming as 27

     Sum of all min & max = 6 + 4 + 4 + 4

                          = 18
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
This problem is mainly an extension of below problem.
Maximum of all subarrays of size k

Method 1 (Simple): Run two loops to generate all subarrays of size k and find maximum and minimum values. Finally, return sum of all maximum and minimum elements.
Time taken by this solution is O(n*k).


Method 2 (Efficient using Dequeue): The idea is to use Dequeue data structure and sliding window concept. We create two empty double-ended queues of size k (‘S’ , ‘G’) that only store indices of elements of current window that are not useless. An element is useless if it can not be maximum or minimum of next subarrays.
*/
#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr, int n, int k)
{

    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k size window

    for (int i = 0; i < k; i++)
    {

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    // remaining windows ko process karlo
    for (int i = k; i < n; i++)
    {

        // next window

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main()
{

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}