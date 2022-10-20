//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// recursive
void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // lrn
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// iterative
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        vector<int> ans;
        if (root == NULL)
            return ans;
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left != NULL)
                st1.push(root->left);
            if (root->right != NULL)
                st1.push(root->right);
        }
        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> postorderTraversal(TreeNode *root)
{

    if (root == NULL)
    {
        return {};
    }
    stack<TreeNode *> st1;

    vector<int> ans;

    st1.push(root);
    while (!st1.empty())
    {
        TreeNode *temp = st1.top();
        st1.pop();

        ans.push_back(temp->val);
        if (temp->left)
        {
            st1.push(temp->left);
        }
        if (temp->right)
        {
            st1.push(temp->right);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;