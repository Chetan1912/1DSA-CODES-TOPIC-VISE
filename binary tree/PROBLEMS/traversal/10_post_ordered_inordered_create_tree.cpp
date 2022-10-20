

////////////////////////////////////////////////////////////////////////////////////////////////////////
// with out map
/
    class Solution
{
public:
    int search(vector<int> &inorder, int inend, int cur)
    {
        for (int i = 0; i <= inend; i++)
        {
            if (inorder[i] == cur)
                return i;
        }
        return -1;
    }
    int posteend;
    TreeNode *helper(vector<int> &postorder, vector<int> &inorder, int instart, int inend)
    {
        if (instart > inend || posteend < 0)
        {
            return NULL;
        }
        int curr = postorder[posteend--];
        TreeNode *root = new TreeNode(curr);
        int pos = search(inorder, inend, curr);
        root->right = helper(postorder, inorder, pos + 1, inend);
        root->left = helper(postorder, inorder, instart, pos - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        posteend = postorder.size() - 1;
        TreeNode *root = helper(postorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// with  map
class Solution
{
public:
    map<int, int> m;
    int posteend;
    TreeNode *helper(vector<int> &postorder, vector<int> &inorder, int instart, int inend)
    {
        if (instart > inend || posteend < 0)
        {
            return NULL;
        }
        int curr = postorder[posteend--];
        TreeNode *root = new TreeNode(curr);
        int pos = m[curr];
        root->right = helper(postorder, inorder, pos + 1, inend);
        root->left = helper(postorder, inorder, instart, pos - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        posteend = postorder.size() - 1;
        TreeNode *root = helper(postorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};