// idea is that if right node is present than add in answer otherwise stor left part in a queue
vector<int> diagonal(Node *root)
{
    // your code here
    queue<Node *> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while (temp)
        {

            if (temp->left != NULL) // storing left node in queue
                q.push(temp->left);

            ans.push_back(temp->data); // storing node data in ans and
            temp = temp->right;        // moving to right
        }
    }

    return ans;
}