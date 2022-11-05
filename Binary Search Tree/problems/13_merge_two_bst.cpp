// # approach 1
void inorder(node *root, vector<int> &tree1)
{
    if (root == NULL)
        return;
    inorder1(root->left, tree1);
    tree1.push_back(root->data);
    inorder1(root->right, tree1)
}
vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] >= b[j])
        {
            ans.push_back(b[j]);
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
        }
    }
    while (i < a.size())
    {
        ans.push_back(a[i])
            i++;
    }
    while (j < b.size())
    {
        ans.push_back(b[j])
            j++;
    }
    return ans;
}
// make the bst fro m the sorted array;
node *sortedarray_to_bst(vector<int> inorder, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    TreeNode<int> *temp = new TreeNode<int>(inorder[mid]);
    temp->left = bdBst(inorder, s, mid - 1);
    temp->right = bdBst(inorder, mid + 1, e);
    return temp;
}
node *mergebst(node *root1, node *root2)
{
    // find the inorder of bboth
    vector<int> tree1;
    vector<int> tree2;
    inorder(root1, tree1);
    inorder(root2, tree2);
    vector<int> ans = merge(tree1, tree2);
    node *root = sortedarray_to_bst(ans, 0, ans.size() - 1);
    return root;
}
// #approach2;
// step 1 convert a bst into sorted
// step2 merge 2 sorted ll
// step 3  sorted ll to bst