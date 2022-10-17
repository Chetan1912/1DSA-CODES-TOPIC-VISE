// recursive
void reverce(stack<int> &myStack, int x)
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
////// can do by the  stack also