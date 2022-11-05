node *lcabst(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if ((root->data > n1 && roor->data < n2) || (root->data > n2 && roor->data < n1))
    {
        return root;
    }
    else if (root->data > n1 && root->data > n2)
    {
        return lcabst(root->left, n1, n2);
    }
    else
    {
        return lcabst(root->right, n1, n2);
    }
    return root;
}

// iterative

node *lcabstiterative(node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if ((root->data > n1 && roor->data < n2) || (root->data > n2 && roor->data < n1))
        {
            return root;
        }
        else if (root->data > n1 && root->data > n2)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
        }
    return root;
}
