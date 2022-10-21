// for inorder
/*
When we are currently at a node, the following cases can arise:

Case 1: When the current node has no left subtree. In this scenario, there is nothing to be traversed on the left side, so we simply print the value of the current node and move to the right of the current node.
Case 2: When there is a left subtree and the right-most child of this left subtree is pointing to null. In this case we need to set the right-most child to point to the current node, instead of NULL and move to the left of the current node.
Case 3: When there is a left subtree and the right-most child of this left-subtree is already pointing to the current node. In this case we know that the left subtree is already visited so we need to print the value of the current node and move to the right of the current node.
*/
\ //please dry run for the batter understanding
    vector<int>
    inorderTraversal(node *root)
{
    vector<int> inorder;

    node *cur = root;
    // because for travel whole tree
    while (cur != NULL)
    {
        // first case if the left not exist
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        // second case ifright exist
        else
        {
            node *prev = cur->left;
            // go the left right to mack link of predecisor of the left child;
            // there may be two case there
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// preorder
vector<int> preorderTraversal(node *root)
{
    vector<int> preorder;

    node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// post order
vector<int> ans;

TreeNode *curr = root;
while (curr != NULL)
{
    if (curr->right == NULL)
    {
        ans.push_back(curr->val);
        curr = curr->left;
    }
    else
    {
        TreeNode *prev = curr->right;
        while (prev->left && prev->left != curr)
        {
            prev = prev->left;
        }

        if (prev->left == NULL)
        {
            ans.push_back(curr->val);
            prev->left = curr;
            curr = curr->right;
        }
        else
        {
            prev->left = NULL;
            curr = curr->left;
        }
    }
}
reverse(ans.begin(), ans.end());
return ans;
}
