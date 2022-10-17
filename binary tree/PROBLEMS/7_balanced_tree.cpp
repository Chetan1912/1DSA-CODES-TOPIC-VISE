// balanced tree if diffrence btn left and right subtree is not more than 1 for all root node ;
// recursive
class Solution
{
public:
    bool balanced = true;
    ;
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ll = helper(root->left);
        int rl = helper(root->right);
        if (abs(ll - rl) > 1)
            balanced = false;
        return max(ll, rl) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        helper(root);
        return balanced;
    }
};
//////////////////////////////////////////////////////////////////////////////////
// can also doo by the previos mathod pair<> in the question no 6;
pair<bool, int> isBalancedFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}
}
;