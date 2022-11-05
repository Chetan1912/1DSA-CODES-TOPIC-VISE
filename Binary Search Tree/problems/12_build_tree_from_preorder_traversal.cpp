// # approach 1   --------->        O(N^2),O(N);
// by visiting the every node 2 times

// reference 3_insert_into_bst
TreeNode *solve(TreeNode *root, int &idx, int n, vector &pre)
{
    if (idx >= n)
        return NULL;
    if (root == NULL)
    {
        root = new ListNode(pre[idx++]);
        return root;
    }
    else if (pre[idx] val)
    {
        root->left = solve(root->left, idx, n, pre);
    }
    else
    {
        root->right = solve(root->right, idx, n, pre);
    }
    return root;
}

public:
TreeNode *bstFromPreorder(vector &preorder)
{
    int n = preorder.size();
    TreeNode *root = NULL;
    root = solve(root, 0, n, preorder);
    return root;
}

// approach 2 by sortin preorder toinorder
// approtch 3
// Approach 3 : Using check BST or not Approach (Most optimised)

// Take an index variable as root element in preorder which is 0, define curent node lower bound as INT_MAX and upper bount as INT_MAX, then call BuildBST.
// At each call create a new node which having value as index element of preorder . recursive call for left and right child, increment index by 1 at each call as well. ( return NULL if index became out of bound or preoreder index value is out of lower or upper bound )
// a. Call recursively for the left node, set upper bound as current node value and lower bound as it is.
// b. Call recursively for the right node, set lower bound as current node value and upper bound as it is.
// return current node at each calls.
// ~Time complexity: O(3N) You will visit single node trice at worst case.
// ~Space Complexity: O(1) We are'nt using any extra space.
class Solution
{
public:
    TreeNode *solve(vector<int> preorder, int min, int max, int &i)
    {
        if (i >= preorder.size())
            return NULL;
        if (preorder[i] < min || preorder[i] > max)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, min, root->val, i);
        root->right = solve(preorder, root->val, max, i);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        int i = 0;
        return solve(preorder, INT_MIN, INT_MAX, i);
    }
};
