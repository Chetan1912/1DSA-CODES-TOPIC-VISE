/////////////////////////////////////////////////////////////////////////////////////////////
// love bbr
pair<int, int> diameterFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int diameter(Node *root)
{

    return diameterFast(root).first;
}
}
;

/////////////////////////////////////////////////////////////////////////////////////////
// best
Idea:
For each node, the diameter is the height of the left node + the height of the right node.
So we use DFS to get the heights recursively, and keep in diameter the maximum seen.

Time Complexity: O(n)
Space Complexity: O(n) - for the recursive calls.

class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left), right = dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return diameter;
    }

private:
    int diameter = 0;
};
/////////////////////////////////////////////////////////////////////////////////////////