Using Vector to store elements and then convert it into BST
Using mid element and then appending it as a root , similarily for the left and right part , after that recursion will handle all the stuffs.

TreeNode* solve(vector<int>&v,int s ,int e)
{
    if (s > e)
        return nullptr;
    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = solve(v, s, mid - 1);
    root->right = solve(v, mid + 1, e);
    return root;
}
TreeNode *sortedListToBST(ListNode *head)
{
    if (!head)
        return nullptr;
    vector<int> v;
    while (head)
    {
        v.push_back(head->val);
        head = head->next;
    }
    int s = 0;
    int e = v.size() - 1;
    return solve(v, s, e);
}

// #approach 2
TreeNode *solve(ListNode *head, ListNode *tail)
{
    if (head == tail)
        return nullptr;
    ListNode *fast = head, *slow = head;
    while (fast != tail and fast->next != tail)
    {
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
        slow = slow->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = solve(head, slow);
    root->right = solve(slow->next, tail);
    return root;
}
TreeNode *sortedListToBST(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *tail = NULL;
    return solve(head, tail);
}