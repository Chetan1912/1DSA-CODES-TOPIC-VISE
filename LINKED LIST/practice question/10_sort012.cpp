/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node *sortList(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    int zeroc = 0;
    int onec = 0;
    int twoc = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroc++;
        }
        else if (temp->data == 1)
        {
            onec++;
        }
        else
        {
            twoc++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroc)
        {
            temp->data = 0;
            zeroc--;
        }
        else if (onec)
        {
            temp->data = 1;
            onec--;
        }
        else
        {
            temp->data = 2;
            twoc--;
        }
        temp = temp->next;
    }
    return head;
}

// ekse
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
void insertat(Node *&tail, Node *temp)
{
    tail->next = temp;
    tail = temp;
}
Node *sortList(Node *head)
{

    Node *zerohead = new Node(0);
    Node *zerotail = zerohead;

    Node *onehead = new Node(0);
    Node *onetail = onehead;

    Node *twohead = new Node(0);
    Node *twotail = twohead;
    Node *temp = head;
    // putting node int the seperate list (dummy list)
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insertat(zerotail, temp);
        }
        else if (temp->data == 1)
        {
            insertat(onetail, temp);
        }
        else
        {
            insertat(twotail, temp);
        }
        temp = temp->next;
    }
    // merge three nodes
    // one list is not empty
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        // one list empty
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;
    //     set head
    head = zerohead->next;
    // delete dummy node;
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}
