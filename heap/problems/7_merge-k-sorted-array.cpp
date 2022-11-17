// #approach 1 in note;
// #apprroch 2
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++

class node
{
public:
    int data;
    int col;
    int row;
    node(int val, int row, int col)
    {
        this->col = col;
        this->row = row;
        data = val;
    }
};
// creates min   heap;
class compare
{
public:
    bool operator()(node &a, node &b)
    {
        return a.data > b.data;
    }
};
class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<node, vector<node>, compare> minheap;
        // sare array k first element ko enter karo heap me;
        for (int i = 0; i < K; i++)
        {
            node d(arr[i][0], i, 0);
            minheap.push(d);
        }
        while (!minheap.empty())
        {
            node curr = minheap.top();
            minheap.pop();
            ans.push_back(curr.data);
            int row = curr.row;
            int col = curr.col;
            // because we want to find that the next pos is smaller than the size() of the row or not;
            if (col + 1 < arr[row].size())
            {
                node d(arr[row][col + 1], row, col + 1);
                minheap.push(d);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends