void solve(TreeNode<int> *root, vector<TreeNode<int> *> &inorder)
{
    if (!root)
        return;
    solve(root->left, inorder);
    inorder.push_back(root);
    solve(root->right, inorder);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    vector<TreeNode<int> *> inorder;
    solve(root, inorder);
    for (int i = 0; i < inorder.size() - 1; i++)
    {
        inorder[i]->left = NULL;
        inorder[i]->right = inorder[i + 1];
    }
    inorder[inorder.size() - 1]->left = NULL;
    inorder[inorder.size() - 1]->right = NULL;
    return inorder[0];
}
// approach 2
// step1 convert a  bst into thhe sorted ll
void inorder(node *curr, node *&prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

// Function to flatten binary tree using
// level order traversal
node *flatten(node *parent)
{
    // Dummy node
    node *dummy = new node(-1);

    // Pointer to previous element
    node *prev = dummy;

    // Calling in-order traversal
    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    node *ret = dummy->right;

    // Delete dummy node
    delete dummy;
    return ret;
}