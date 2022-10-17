#Intuition recursive
<!--Describe your first thoughts on how to solve this problem.-->

#Approach recursive
    <!--Describe your approach to solving the problem.-->

#Complexity o(n);
    - Time complexity : <!--Add your time complexity here, e.g.$$O(n) $$-->

                        -
                        Space complexity : o(n)<!--Add your space complexity here, e.g.$$O(n) $$-->

#Code
```
                                           /**
                                            * Definition for a binary tree node.
                                            * struct TreeNode {
                                            *     int val;
                                            *     TreeNode *left;
                                            *     TreeNode *right;
                                            *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
                                            *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
                                            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
                                            * };
                                            */
                                           class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.emplace_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        inorder(root, ans);
        return ans;
    }
};
```