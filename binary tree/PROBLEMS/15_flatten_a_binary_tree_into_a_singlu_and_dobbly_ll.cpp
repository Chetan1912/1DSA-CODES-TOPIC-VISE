/*114. Flatten Binary Tree to Linked List
Medium
9.5K
497
Companies
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 */
///////////////////////////////////////////////////////////////////////////////////////////////
// singlt. with preorder
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr->left;

                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};
// recursive
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        if (root->left)
        {
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            while (root->right)
                root = root->right;
            root->right = right;
        }
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
// dobbly with inorder
class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        Node *curr = root, *head = NULL, *prev = NULL;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if (head == NULL)
                    head = curr;
                curr->left = prev;
                if (prev != NULL)
                    prev->right = curr;
                prev = curr;
                curr = curr->right;
            }
            else
            {
                Node *trav = curr->left;
                while (trav->right != NULL && trav->right != curr)
                    trav = trav->right;

                if (trav->right == NULL)
                {
                    trav->right = curr;
                    curr = curr->left;
                }
                else
                {
                    curr->left = prev;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return head;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// recursive
class Solution
{
public:
    Node *prev = NULL, *start = NULL;

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);

        if (start == NULL)
        {
            start = root;
            prev = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
            prev = root;
        }
        inorder(root->right);
    }

    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        inorder(root);
        return start;
    }
};
