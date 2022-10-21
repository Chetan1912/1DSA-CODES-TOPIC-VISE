/*105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
11.3K
318
Companies
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
Accepted
870.1K
Submissions
1.4M
Acceptance Rate
60.7%
Seen this question in a real interview before?
1/4
Yes
No
Related Topics
Copyright ©️ 2022 LeetCode All ri
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// nonmap
O(n2)
o(n) class Solution
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
    int pre = 0;
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int instart, int inend, int preend)
    {
        if (instart > inend || pre > preend)
        {
            return NULL;
        }
        int curr = preorder[pre];
        pre++;
        TreeNode *root = new TreeNode(curr);
        int pos = search(inorder, inend, curr);
        root->left = helper(preorder, inorder, instart, pos - 1, preend);
        root->right = helper(preorder, inorder, pos + 1, inend, preend);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        TreeNode *root = helper(preorder, inorder, 0, inorder.size() - 1, preorder.size() - 1);
        return root;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// map
O(nlogn)
o(n) class Solution
{
public:
    int pre = 0;
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int instart, int inend, int preend, map<int, int> &m)
    {
        if (instart > inend || pre > preend)
        {
            return NULL;
        }
        int curr = preorder[pre];
        pre++;
        TreeNode *root = new TreeNode(curr);
        int pos = m[curr];
        root->left = helper(preorder, inorder, instart, pos - 1, preend, m);
        root->right = helper(preorder, inorder, pos + 1, inend, preend, m);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        TreeNode *root = helper(preorder, inorder, 0, inorder.size() - 1, preorder.size() - 1, m);
        return root;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  iterative
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return NULL;
        }

        TreeNode *head = new TreeNode(preorder[0]);
        stack<TreeNode *> s;
        s.push(head);
        int i = 1;
        int j = 0;

        while (i < preorder.size())
        {
            TreeNode *temp = NULL;
            TreeNode *t = new TreeNode(preorder[i]);
            while (!s.empty() && s.top()->val == inorder[j])
            {
                temp = s.top();
                s.pop();
                j++;
            }

            if (temp)
            {
                temp->right = t;
            }
            else
            {
                s.top()->left = t;
            }

            s.push(t);
            i++;
        }

        return head;
    }
}