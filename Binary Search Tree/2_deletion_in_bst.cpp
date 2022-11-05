TreeNode *deleteNode(TreeNode *root, int val)
{
    if (!root)
        return root;

    if (val < root->val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        /* Leaf node case */
        if (!root->left && !root->right)
        {
            delete (root);
            return NULL;
        }
        /* 1 child case */
        if (!root->left)
        {
            TreeNode *ret = root->right;
            delete (root);
            return ret;
        }
        else if (!root->right)
        {
            TreeNode *ret = root->left;
            delete (root);
            return ret;
        }
        /* 2 child case */
        if (root->left && root->right)
        {
            TreeNode *tmp = root->right;
            // find inorder succesor
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            // for delete the svaped successor
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
            return root;
        }
    }
    return root;
}
}
;
