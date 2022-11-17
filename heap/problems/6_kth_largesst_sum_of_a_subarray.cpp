#approatch 1
#include <bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
    vector<int> ansa;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = i; j < n; j++)
        {
            ans = ans + arr[j];
            ansa.push_back(ans);
        }
    }
    sort(ansa.begin(), ansa.end());
    return ansa[ansa.size() - k];
}

#optimised
#approatch 1
#include <bits/stdc++.h>
#include <queue>
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> ansa;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = i; j < n; j++)
        {
            ans = ans + arr[j];
            if (ans.size() < k)
            {
                heap.push_back(ans);
            }
            else
            {
                if (sum > heap.top())
                {
                    heap.pop();
                    heap.push(sum);
                }
            }
        }
    }

    return heap.top();
