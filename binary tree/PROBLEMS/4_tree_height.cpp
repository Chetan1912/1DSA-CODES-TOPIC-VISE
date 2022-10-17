/// @brief ///////////iterative
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int height = 0;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            height++;
        }
        return height;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// recursive
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ll = maxDepth(root->left);
        int rl = maxDepth(root->right);
        return max(ll, rl) + 1;
    }
}