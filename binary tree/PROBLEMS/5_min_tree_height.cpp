/// @brief //////////////// by level order traversal
class Solution
{
public:
    int level = 0;
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        queue<TreeNode *> q;
        int level = 0;

        q.push(root);
        while (!q.empty())
        {
            int breadth = q.size();
            level++;
            for (int i = 0; i < breadth; i++)
            {
                TreeNode *parent = q.front();
                q.pop();

                if (parent->left)
                    q.push(parent->left);
                if (parent->right)
                    q.push(parent->right);

                if (!parent->left && !parent->right)
                    return level; // leaf node
            }
        }

        return level;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// recursive
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            return minDepth(root->right) + 1;
        }
        else
        {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
}
// com do by lebvelorder traversal.
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int height = 0;
        while (!q.empty())
        {
            int s = q.size();
            height++;
            while (s--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                if (t->left == NULL && t->right == NULL)
                {
                    return height;
                }
            }
        }
        return height;
    }
};