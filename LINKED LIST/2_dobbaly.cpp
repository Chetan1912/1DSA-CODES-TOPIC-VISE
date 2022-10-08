#include <iostream>
using namespace std;
class NODE
{
public:
    int data;
    NODE *prev;
    NODE *next; // because jaise int k liye int pointer float k liye float vaise hi next node ko point karne k liye NODE type pointer

    // constructur for insert the data directly
    NODE(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    // it is destroyer for delete the memory
    ~NODE() // it is note cumpulsory
    {
        if (this->next != NULL)
        {
            this->next = NULL;
            this->prev = NULL;
            delete next;
        }
        cout << "i am called" << endl;
    }
};
// insert at the head    // TAIL IS PASSED BECAUSE  WANT TO HANDEL THE EMPTY LIST
void insertathead(NODE *&head, NODE *&tail, int d)
{ // EMPTY LIST
    if (head == NULL)
    {
        NODE *TEMP = new NODE(d);
        tail = TEMP;
        head = TEMP;
    }
    else
    {
        NODE *temp = new NODE(d);
        temp->next = head;
        head = temp;
        temp->next->prev = temp;
    }
}
// insert at tail  // HEAD IS PASSED BECAUSE  WANT TO HANDEL THE EMPTY LIST
void taile(NODE *&tail, NODE *&head, int d)
{
    if (tail == NULL)
    {
        NODE *TEMP = new NODE(d);
        tail = TEMP;
        head = TEMP;
    }
    else
    {

        NODE *temp = new NODE(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
// insert at any
//  insert at the any pos
void insertatPOS(NODE *&head, NODE *&tail, int pos, int data)
{ // insert at start
    if (pos == 1)
    {
        insertathead(head, tail, data);
        return;
    }

    NODE *temp = head;
    int cnt = 1;
    // for the temp pointer before the position
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at last
    if (temp->next == NULL)
    {
        taile(tail, head, data);
        return;
    }

    NODE *nodetoins = new NODE(data);
    nodetoins->next = temp->next;
    temp->next->prev = nodetoins;
    nodetoins->prev = temp;
    temp->next = nodetoins;
}
// delete
void delenode(int position, NODE *&head, NODE *&tail)
{ // for the blank  last node
    if (head == NULL || tail == NULL)
    {
        cout << "there are not any node to delete" << endl;
        return;
    }
    // deleting first or start node

    if (position == 1)
    {
        NODE *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL; // because for the delete the node it will not point to the any node
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        NODE *curr = head;
        NODE *prev2 = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev2 = curr;
            curr = curr->next;
            cnt++;
        }

        // for the last node tail position management
        if (curr == tail)
        {
            tail = prev2;
        }
        curr->prev = NULL;
        prev2->next = curr->next;
        curr->next = NULL;
        // FORE THE LAST NODE TAIL;

        delete curr;
    }
}

void printl(NODE *&head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
}
int main()
{
    NODE *nodel = new NODE(10);
    NODE *head = nodel;
    NODE *tail = nodel;
    insertathead(head, tail, 50);
    insertathead(head, tail, 50);
    insertathead(head, tail, 50);
    insertathead(head, tail, 50);
    insertathead(head, tail, 50);
    printl(head);
    cout << endl;
    taile(tail, head, 5055);
    taile(tail, head, 5055);
    taile(tail, head, 5055);
    taile(tail, head, 5055);
    taile(tail, head, 5055);
    printl(head);
    // insert at the pos
    cout << endl;

    insertatPOS(head, tail, 1, 100);
    insertatPOS(head, tail, 5, 1000);
    insertatPOS(head, tail, 13, 1000);
    printl(head);
    cout << endl;

    delenode(14, head, tail);
    cout << tail->data << endl;

    printl(head);

    // cout << head->data << endl;
    // cout << tail->data << endl;
    // cout << head->next->prev->data << endl;
}