// not same as leet code 25
Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    // step3: return head of reversed list
    return prev;
}
// recursive
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy, *nex = dummy, *pre = dummy;
        int cnt = 0;

        // Finding length of linked list - For Breaking list in length/k groups
        while (curr->next)
        {
            curr = curr->next;
            cnt++;
        }

        while (cnt >= k)
        {
            curr = pre->next;
            nex = curr->next;

            // Reversing the links is performed k-1 times for each group
            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }

            pre = curr;
            cnt -= k;
        }
        return dummy->next;
    }
};