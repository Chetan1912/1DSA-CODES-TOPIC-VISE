/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
437. Path Sum III
Medium
8.8K
422
Companies
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
*/
class Solution
{
public:
    void solve(TreeNode *r, vector<int> &path, int &count, int targetsum)
    {
        if (r == NULL)
            return;
        path.push_back(r->val);
        solve(r->left, path, count, targetsum);
        solve(r->right, path, count, targetsum);
        long long int sum = 0;
        int size = path.size();
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == targetsum)
                count++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        vector<int> path;
        int count = 0;
        solve(root, path, count, targetSum);
        return count;
    }
};