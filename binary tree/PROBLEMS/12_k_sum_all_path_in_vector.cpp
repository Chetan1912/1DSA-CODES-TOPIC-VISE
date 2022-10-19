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
// all the path which sum is equal to k;
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[4,11,7],[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
4+11+7=22;
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
*/

Tc = o(n * h ^ 2) sc = o(height of tree);
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> help;
    void solve(TreeNode *r, vector<int> &path, int targetsum)
    {
        if (r == NULL)
            return;
        path.push_back(r->val);
        solve(r->left, path, targetsum);
        solve(r->right, path, targetsum);
        long long int sum = 0;
        int size = path.size();
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == targetsum)
            {
                for (int m = i; m < size; m++)
                {
                    help.push_back(path[m]);
                }
                ans.push_back(help);
                help.clear();
            }
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> path;
        solve(root, path, targetSum);
        return ans;
    }
};