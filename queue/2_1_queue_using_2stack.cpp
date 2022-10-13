#include <bits/stdc++.h>
class MyQueue
{
public:
    stack<int> st1, st2;

    MyQueue()
    {
    }

    void push(int x)
    {
        while (!st1.empty())
        {
            int tp = st1.top();
            st1.pop();
            st2.push(tp);
        }
        st1.push(x);
        while (!st2.empty())
        {
            int tp = st2.top();
            st2.pop();
            st1.push(tp);
        }
    }

    int pop()
    {
        if (st1.empty())
            return -1;
        int tp = st1.top();
        st1.pop();
        return tp;
    }

    int peek()
    {
        if (st1.empty())
            return -1;
        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */