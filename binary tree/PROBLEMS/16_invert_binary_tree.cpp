/*   4
   /    \
  2      7
 / \    / \
1 3     6  9
We are required to write a JavaScript function that takes in the root of this binary tree and inverts it.

The inverted version of this above binary tree will look like this −

      4
      / \
    7    2
   / \ / \
   9 6 3 1
*/
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// class Solution
// {
// public:
//     TreeNode *invertTree(TreeNode *root)
//     {
//         if (root == NULL)
//         {
//             return root;
//         }
//         invertTree(root->left);
//         invertTree(root->right);

//         TreeNode *temp = root->left;
//         root->left = root->right;
//         root->right = temp;

//         return root;
//     }
// };
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// iterative
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return NULL;
        }
        queue<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty())
        {
            TreeNode *node = todo.front();
            todo.pop();
            swap(node->left, node->right);
            // the order of left push and right push not matter
            if (node->left)
            {
                todo.push(node->left);
            }
            if (node->right)
            {
                todo.push(node->right);
            }
        }
        return root;
    }
};