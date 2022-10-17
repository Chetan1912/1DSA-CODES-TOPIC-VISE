//{ Driver Code Starts
First negative integer in every window of size k
EasyAccuracy: 54.27%Submissions: 52852Points: 2
LampGeek Week 2022 is LIVE! Click Here to View All the Exciting Offers!
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
-105 <= A[i] <= 105
1 <= K <= N

View Bookmarked Problems 
Company Tags
Topic Tags
Related Courses
If you are facing any issue on this page. Please let us know.
Output Window
Problem Solved Successfully
Test Cases Passed: 
10100 /10100
Total Points Scored: 
2 /2

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    deque<long long int> q;
    vector<long long> ans;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            q.push_back(i);
        }
    }
    // for the first element
    if (q.size() > 0)
    {
        ans.push_back(A[q.front()]);
    }
    else
        ans.push_back(0);
    for (int i = K; i < N; i++)
    {
        // pushing and poping
        if (!q.empty() && (i - q.front()) >= K)
        {
            q.pop_front();
        }
        if (A[i] < 0)
            q.push_back(i);
        if (q.size() > 0)
            ans.push_back(A[q.front()]);
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}