#include <bits/stdc++.h>
void pushatbottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int ele = myStack.top();
    myStack.pop();
    pushatbottom(myStack, x);
    myStack.push(ele);
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    pushatbottom(myStack, x);
    return myStack;
}
