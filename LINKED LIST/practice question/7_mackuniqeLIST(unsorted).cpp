
Q.Remove duplicates in unsorted list using map
#include <bits/stdc++.h>
    Node *
    removeDuplicates(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    unordered_map<int, int> visited;

    while (curr != NULL)
    {
        if (!visited[curr->data])
        {
            visited[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        curr = prev->next;
    }
    return head;
}
/ using o(^2) TIME COMPLEXITY

    Node *curr = head;

while (curr != NULL)
{
    Node *temp = curr;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->next->data == curr->data)
        {
            Node *next_next = temp->next->next;
            Node *todelete = temp->next;
            delete (todelete);
            temp->next = next_next;
        }
        else
        {
            temp = temp->next;
        }
    }
    curr = curr->next;
}
return head