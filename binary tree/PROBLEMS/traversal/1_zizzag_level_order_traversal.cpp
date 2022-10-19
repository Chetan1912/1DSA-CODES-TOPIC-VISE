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
Input : root = [ 3, 9, 20, null, null, 15, 7 ] Output : [ [3], [ 20, 9 ], [ 15, 7 ] ] Example 2 : class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool line = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> help(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (line)
                {
                    help[i] = temp->val;
                }
                else
                {
                    help[size - i - 1] = temp->val;
                }
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            line = !line;
            ans.push_back(help);
        }
        return ans;
    }
};