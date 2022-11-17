// approatch 1(brote force) in o(n)
class Solution
{
public:
    int cnt = 0;
    void count(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        count(root->left);
        cnt++;
        count(root->right);
    }

    int countNodes(TreeNode *root)
    {
        count(root);
        return cnt;
    }
};
// approatch less then o(log^2n)
class Solution
{
public:
    int findLeftHeight(TreeNode *node)
    { // calculating left height by normal traversal
        int height = 0;
        while (node)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode *node)
    { // calculating right height by normal traversal
        int height = 0;
        while (node)
        {
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = findLeftHeight(root);  // find left height of tree
        int rh = findRightHeight(root); // find right height of tree
        if (lh == rh)
            return (1 << lh) - 1;                                    // if balaced tree(having 0 or 2 child of every node) then we'll use [n = 2^h - 1].
        return 1 + countNodes(root->left) + countNodes(root->right); // if not a balanced tree then we'll use [1+left subtree+right subtree}
    }
};

// T.C => O(log^2 N) [one "log N" for traversing x one "log N" for finding height]
// S.C => O(log N) [recursive space equal to height of the tree]