
class Solution
{
private:
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    Node *reverse(Node *head)
    {

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
        {
            return true;
        }

        // step 1 -> find Middle
        Node *middle = getMid(head);
        // cout << "Middle " << middle->data << endl;

        // step2 -> reverse List after Middle
        Node *temp = middle->next;
        middle->next = reverse(temp);

        // step3 - Compare both halves
        Node *head1 = head;
        Node *head2 = middle->next;

        while (head2 != NULL)
        {
            if (head2->data != head1->data)
            {
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // step4 - repeat step 2
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
}
// else
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;

        // Push the elements in first half into the stack
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the length of LL is odd, ignore the middle point
        if (fast != nullptr)
            slow = slow->next;

        // Now compare elements in stack with the elements in second half of the LL
        while (slow != nullptr)
        {
            if (slow->val != s.top())
                return false;
            else
            {
                s.pop();
                slow = slow->next;
            }
        }

        return true;
    }
};