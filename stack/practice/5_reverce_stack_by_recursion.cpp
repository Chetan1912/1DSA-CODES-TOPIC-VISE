#include <bits/stdc++.h>
void pushatbottom(stack<int> &myStack)
{
    if (myStack.empty())
    {
        return;
    }
    int ele = myStack.top();
    myStack.pop();
    pushatbottom(myStack);
    myStack.push(ele);
}
stack<int> reverce(stack<int> &myStack)
{
    pushatbottom(myStack);
    return myStack;
}