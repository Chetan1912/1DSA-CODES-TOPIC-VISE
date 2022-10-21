/*889. Construct Binary Tree from Preorder and Postorder Traversal
Medium
2.2K
94
Companies
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.



Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]


Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
Accepted
81.6K
Submissions
115.3K
Acc
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// recursive
class Solution
{
public:
    int preidx = 0, postidx = 0;
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        TreeNode *root = new TreeNode(pre[preidx++]);
        if (root->val != post[postidx])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[postidx])
            root->right = constructFromPrePost(pre, post);
        postidx++;
        return root;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// iterative
// Approach 1 : -Brute Force

// Time Complexity : -O(N *N)

//   Space Complexity : -O(height of tree i.e.O(logN))

class Solution
{
public:
    // search element in postorder array

    int search(vector<int> &post, int start, int end, int val)
    {
        for (int i = start; i <= end; i++)
        {
            if (post[i] == val)
                return i;
        }

        return -1;
    }

    // pre_idx keeps track of element of preorder array

    int pre_idx = 0;

    // construct tree

    TreeNode *construct(vector<int> &pre, vector<int> &post, int start, int end)
    {
        // base case

        if (start > end || pre_idx >= pre.size())
            return NULL;

        // create a node put value as pre[pre_idx]

        TreeNode *root = new TreeNode(pre[pre_idx]);

        pre_idx++;

        // if there is only one element in range of [start, end] or pre_idx is the last index of pre array

        if (pre_idx >= pre.size() || start == end)
            return root;

        // search the index of pre[pre_idx] in post array

        int idx = search(post, start, end, pre[pre_idx]);

        // construct left subtree

        root->left = construct(pre, post, start, idx);

        // construct right subtree, as we can see that we are not including the last element of range, because we have already included as root

        root->right = construct(pre, post, idx + 1, end - 1);

        // return root

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {

        int n = preorder.size();

        return construct(preorder, postorder, 0, n - 1);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Approach 2 : -Optimized

//  Time Complexity : -O(N)
// if used only map not unordered map than it wil be nlogn
// Space Complexity : -O(N)
class Solution
{
public:
    // mp store the index of corresponding element of postorder

    unordered_map<int, int> mp;

    // pre_idx keeps track of element of preorder array

    int pre_idx = 0;

    // construct tree

    TreeNode *construct(vector<int> &pre, vector<int> &post, int start, int end)
    {
        // base case

        if (start > end || pre_idx >= pre.size())
            return NULL;

        // create a node put value as pre[pre_idx]

        TreeNode *root = new TreeNode(pre[pre_idx]);

        pre_idx++;

        // if there is only one element in range of [start, end] or pre_idx is the last index of pre array

        if (pre_idx >= pre.size() || start == end)
            return root;

        // get the index of pre[pre_idx] from map

        int idx = mp[pre[pre_idx]];

        // construct left subtree

        root->left = construct(pre, post, start, idx);

        // construct right subtree, as we can see that we are not including the last element of range, because we have already included as root

        root->right = construct(pre, post, idx + 1, end - 1);

        // return root

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {

        int n = preorder.size();

        // insert the index of element of postorder into map

        for (int i = 0; i < n; i++)
        {
            mp[postorder[i]] = i;
        }

        return construct(preorder, postorder, 0, n - 1);
    }
};