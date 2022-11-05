int solve(node *root, int &i, int k)
{
    if (root == NULL)
        return -1;
    //   L(left)
    int left = solve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    // N(node)
    i++;
    if (i == k)
    {
        return root->data;
    }
    // R
    return solve(root->right, i, k);
}

int KthSmallestelement(node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    retrurn ans;
}
// approatch 2
class Solution
{
    int x = 0;
    int ans = 0;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                x++;
                if (x == k)
                    ans = curr->val;
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    x++;
                    if (x == k)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};