/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
in sorted ll;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newhead = deleteDuplicates(head->next);
        if (head->val == newhead->val)
        {
            return newhead;
        }
        else
        {
            head->next = newhead;
            return head;
        }
    }
};

// iterative
Node *uniqueSortedList(Node *head)
{
    // empty List
    if (head == NULL)
        return NULL;

    // non empty list
    Node *curr = head;

    while (curr != NULL)
    {

        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else // not equal
        {
            curr = curr->next;
        }
    }

    return head;
}