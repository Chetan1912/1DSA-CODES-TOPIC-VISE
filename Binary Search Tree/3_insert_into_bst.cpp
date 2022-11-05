Node *insertintobst(Node *root, int d)
{
    // base casae
    if (root == NULL)

    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // insert into the right
        root->right = insertintobst(root->right, d);
    }
    else
    {
        // left me jao
        root->left = insertintobst(root->left, d);
    }
    return root;
}

// take input function
void takeiinput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertintobst(root, data);
        cin >> data;
    }
}