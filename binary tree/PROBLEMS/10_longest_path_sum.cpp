//{ Driver Code Starts
// Initial Template for C++
///////////////////////////////////////////////////////////////////////..
/*
Input:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6
Output: 13
Explanation:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6

The highlighted nodes (4, 2, 1, 6) above are
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13*/

class Solution
{
public:
    void solve(Node *root, int sum, int &maxsum, int len, int &maxlen)
    {
        if (root == NULL)
        {
            if (len > maxlen)
            {
                maxsum = sum;
                maxlen = len;
            }
            else if (len == maxlen)
            {
                maxsum = max(sum, maxsum);
            }
            return;
        }
        sum = sum + root->data;
        solve(root->left, sum, maxsum, len + 1, maxlen);
        solve(root->right, sum, maxsum, len + 1, maxlen);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int maxsum = INT_MIN;
        solve(root, sum, maxsum, len, maxlen);
        return maxsum;
    }
};

//{ Driver Code Starts.
////////////////////////////////////////////////////////////////////////////
class Solution
{
public:
    vector<int> solve(Node *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        vector<int> a = solve(root->left);
        vector<int> b = solve(root->right);
        if (a[0] > b[0])
            return {a[0] + 1, a[1] + root->data};
        else if (a[0] < b[0])
            return {b[0] + 1, b[1] + root->data};
        else
            return {a[0] + 1, max(a[1], b[1]) + root->data};
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        vector<int> ans = solve(root);

        return ans[1];
    }
};
