// iterative
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *dummy = new ListNode(-1);
        ListNode *next = head->next;
        while (head)
        {
            next = head->next;
            ListNode *temp = dummy;
            while (temp->next != NULL && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy->next;
    }
};
// recursive
ListNode *insertionSortList(ListNode *L)
{
    if (L == NULL || L->next == NULL)
        return L;
    ListNode *Head = L;
    insertionSortList(L->next);
    int temp = L->val;

    while (L->next != NULL && temp > L->next->val)
    {
        L->val = L->next->val;
        L = L->next;
    }

    L->val = temp;
    return Head;
}
