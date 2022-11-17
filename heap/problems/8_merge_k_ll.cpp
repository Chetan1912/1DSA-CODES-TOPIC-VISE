bruteforce
    //  * Definition for singly-linked list.
    //  * struct ListNode
    //  {
    //      *int val;
    //      *ListNode *next;
    //      *ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){}
    //                                                                                                                                        *
    //  };
    //  * /
    class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> v;
        for (auto i : lists)
        {
            while (i != NULL)
            {
                v.push_back(i->val);
                i = i->next;
            }
        }
        ListNode *head = new ListNode;
        ListNode *temp = head;
        sort(v.begin(), v.end());
        for (auto i : v)
        {
            ListNode *st = new ListNode(i);
            temp->next = st;
            temp = temp->next;
        }
        return head->next;
    }
};

//  #optimised
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
class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &v)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *anstail = dummy;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != NULL)
            {
                pq.push(v[i]);
            }
        }
        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();
            // makeinto the ll
            if (temp->next)
            {
                pq.push(temp->next);
            }
            anstail->next = temp;
            anstail = temp;
        }
        return dummy->next;
    }
};