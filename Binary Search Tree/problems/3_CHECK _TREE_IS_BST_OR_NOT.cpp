#include <iostream>
using namespace std;
// approatch 1
class Solution
{
public:
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }

    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        inOrder(root);
        for (int i = 1; i < tree.size(); i++)
            if (tree[i] <= tree[i - 1])
                return false;
        return true;
    }

private:
    vector<int> tree;
};
// approatch 2
bool is BST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data >= min && rrot->data <= max)
    {
        bool left = isBST(root->left, min, root->data);   // because there is min val same in the left part
        bool right = isBST(root->right, root->data, max); // max value is same in right part
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validate2(Node *root, int max, int min)
{
    return isBST(root, INT_MIN, INT_MAX);
}
// leet code
class Solution
{
public:
    bool checkBST(TreeNode *root, long lowerBound, long upperBound)
    {
        if (!root)
            return true;
        if (root->val > lowerBound && root->val < upperBound)
        {
            bool left = checkBST(root->left, lowerBound, root->val);
            bool right = checkBST(root->right, root->val, upperBound);
            return left && right;
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};
// note the constrain
// The number of nodes in the tree is in the range[1, 104].- 231 <= Node.val <= 231 - 1

// apporch 3 morrice
bool isValidBST(TreeNode *root)
{
    vector<int> v;
    while (root)
    {
        if (!root->left)
        {
            v.push_back(root->val);
            root = root->right;
        }
        else
        {
            TreeNode *r = root->left;
            while (r->right && r->right != root)
            {
                r = r->right;
            }
            if (!r->right)
            {
                r->right = root;
                root = root->left;
            }
            else
            {
                r->right = NULL;
                v.push_back(root->val);
                root = root->right;
            }
        }
    }
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
    if (v.size() != m.size())
    {
        return false;
    }
    vector<int> v1 = v;
    sort(v1.begin(), v1.end());
    if (v1 == v)
    {
        return true;
    }
    return false;
}