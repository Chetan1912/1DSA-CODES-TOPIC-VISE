// 1) ITERATIVE
#include <bits/stdc++.h>
#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *above;
    while (curr != NULL)
    {
        above = curr->next;

        curr->next = prev;
        prev = curr;
        curr = above;
    }

    return prev;
}
// RECURSIVE
void reverce(Node<int> *&head, Node<int> *&curr, Node<int> *&prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    LinkedListNode<int> *above = curr->next;
    reverce(head, above, curr);
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    reverce(head, curr, prev);
    return prev;
}
