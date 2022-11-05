void inordergetinarray(TreeNode<int> *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    inordergetinarray(root->left, inorder);
    inorder.push_back(root->data);
    inordergetinarray(root->right, inorder);
}
TreeNode<int> *bdBst(vector<int> inorder, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    TreeNode<int> *temp = new TreeNode<int>(inorder[mid]);
    temp->left = bdBst(inorder, s, mid - 1);
    temp->right = bdBst(inorder, mid + 1, e);
    return temp;
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> inorder;
    inordergetinarray(root, inorder);
    TreeNode<int> *tp = bdBst(inorder, 0, inorder.size() - 1);
    return tp;
}