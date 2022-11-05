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
TreeNode<int> *balancedBst(vector<int> inorder)
{

    TreeNode<int> *tp = bdBst(inorder, 0, inorder.size() - 1);
    return tp;
}
