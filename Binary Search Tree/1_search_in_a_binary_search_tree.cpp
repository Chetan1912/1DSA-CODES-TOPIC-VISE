// itertive
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *temp = root;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                return temp;
            }
            else if (val < temp->val)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return NULL;
    }
};
////////////////////////////////////////////////////////
// recursion
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        else if (val < root->val)
            return searchBST(root->left, val);
        else if (val > root->val)
            return searchBST(root->right, val);
        return root;
    }
};
