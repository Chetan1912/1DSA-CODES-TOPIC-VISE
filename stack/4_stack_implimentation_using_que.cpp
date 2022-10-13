// using one stack
////////////////////////////////////////////////////////////////////////////////////////////

class MyStack
{
public:
    queue<int> q;
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * @brief
 *
 */
*MyStack *obj = new MyStack();
*obj->push(x);
*int param_2 = obj->pop();
*int param_3 = obj->top();
*bool param_4 = obj->empty();
* /
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    // using two stack
    class MyStack
{
public:
    queue<int> q1, q2;

    MyStack()
    {
    }

    void push(int x)
    {
        while (!q1.empty())
        {
            int data = q1.front();
            q1.pop();
            q2.push(data);
        }
        q1.push(x);
        while (!q2.empty())
        {
            int data = q2.front();
            q2.pop();
            q1.push(data);
        }
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int data = q1.front();
        q1.pop();
        return data;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */