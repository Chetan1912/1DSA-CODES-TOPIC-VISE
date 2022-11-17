void convert(BinaryTreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }

    convert(root->left, inorder);  // Left Call
    inorder.push_back(root->data); // Root Data
    convert(root->right, inorder); // Right Call
}
void fill_pre(BinaryTreeNode *root, vector<int> &inorder, int &index)
{
    if (root == NULL)
    {
        return;
    }

    root->data = inorder[index++];
    fill_pre(root->left, inorder, index);  // Left Call
    fill_pre(root->right, inorder, index); // Right call
}
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> inorder;
    int i = 0;

    convert(root, inorder);

    fill_pre(root, inorder, i);
    return root;
}