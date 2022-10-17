//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends

// User function Template for C++
void reverce(queue<int> &myqueue, int k, int cnt)
{
    if (cnt > k - 1 || myqueue.empty())
    {
        return;
    }
    int ele = myqueue.front();
    myqueue.pop();
    reverce(myqueue, k, cnt + 1);
    myqueue.push(ele);
}
// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    int cnt = 0;

    reverce(q, k, cnt);
    for (int i = 0; i < q.size() - k; i++)
    {
        int q1 = q.front();
        q.pop();
        q.push(q1);
    }
    return q;
}
// sir ki way is by stack;;;;