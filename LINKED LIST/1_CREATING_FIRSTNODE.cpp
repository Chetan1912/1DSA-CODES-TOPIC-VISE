#include <iostream>
using namespace std;
class NODE
{
public:
    int data;
    NODE *next; // because jaise int k liye int pointer float k liye float vaise hi next node ko point karne k liye NODE type pointer

    // constructur for insert the data directly
    NODE(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // it is destroyer for delete the memory
    // ~NODE() // it is note cumpulsory
    // {
    //     if (this->next != NULL)
    //     {
    //         this->next = NULL;
    //         delete next;
    //     }
    //     cout << "i am called" << endl;
    // }
};
// inserting at the head;
void insertathead(int data, NODE *&head)
{
    NODE *temp = new NODE(data);
    temp->next = head;
    head = temp;
}
// function insert at tail;
void insertattail(int data, NODE *&tail)
{
    NODE *temp = new NODE(data);
    tail->next = temp;
    tail = temp;
}
// insert at the any pos
void insertatPOS(NODE *&head, NODE *&tail, int pos, int data)
{ // insert at start
    if (pos == 1)
    {
        insertathead(data, head);
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
        insertattail(data, tail);
        return;
    }

    NODE *nodetoins = new NODE(data);
    nodetoins->next = temp->next;
    temp->next = nodetoins;
}
// FOR DELETE THE NODE
// tele is here for delete the node of the llast position
void delenode(int pos, NODE *&head, NODE *&tail)
{ // if tere is note any node then

    if (head == NULL || tail == NULL)
    {
        cout << "there are not any node to delete" << endl;
    }
    {
        /* code */
    }

    if (pos == 1)
    {
        NODE *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL; // because for the delete the node it will not point to the any node
        delete temp;
    }
    else
    {
        // deleteing the middel or the last node
        NODE *curr = head;
        NODE *prev = NULL;
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
    NODE *HEAD = nodel;
    NODE *tail = nodel;
    insertathead(5, HEAD);
    insertathead(4, HEAD);
    insertathead(3, HEAD);
    insertathead(2, HEAD);
    insertathead(1, HEAD);
    // insertathead(0, HEAD);
    // insert at tail
    insertattail(55, tail);
    insertattail(55, tail);
    insertattail(55, tail);
    insertattail(55, tail);
    insertattail(58, tail);
    printl(HEAD);
    cout << endl;
    // insert at any pos
    insertatPOS(HEAD, tail, 12, 100);

    printl(HEAD);
    cout << endl;
    delenode(12, HEAD, tail);

    printl(HEAD);
    cout << tail->data;

    // cout << HEAD->data << endl;
    // cout << tail->data;
}