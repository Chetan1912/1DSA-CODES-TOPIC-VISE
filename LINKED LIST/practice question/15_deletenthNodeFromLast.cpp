

ListNode *fast = head;
ListNode *slow = head;

for (int i = 0; i < n; i++)
{
    fast = fast->next;
}

if (fast == nullptr)
    return head->next;

while (fast->next)
{
    slow = slow->next;
    fast = fast->next;
}

slow->next = slow->next->next;
return head;

// ms soln
//////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution
{
public:
    void delenode(int pos, ListNode *&head, ListNode *&tail)
    { // if tere is note any node then

        if (head == NULL || tail == NULL)
        {
            return;
        }
        if (pos == 1)
        {
            ListNode *temp = head;
            head = head->next;
            // memory free
            temp->next = NULL;
            delete temp;
        }
        else
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            int cnt = 1;
            while (cnt < pos)
            {
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            // for the last node tail position management
            if (curr == tail)
            {
                tail = prev;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int len = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }
        int pt = len - n + 1;
        delenode(pt, head, temp);

        return head;
    }
};