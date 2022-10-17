void count(BinaryTreeNode<int> *r, int &cnt)
{
    if (r == NULL)
    {
        return;
    }
    count(r->left, cnt);
    if (r->left == NULL && r->right == NULL)
        cnt++;
    count(r->right, cnt);
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int cnt = 0;
    count(root, cnt);
    return cnt;
}