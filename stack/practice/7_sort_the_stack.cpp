time complaxity o(n ^ 2) space complaxity o(n ^ 2) because of the two recursion with two stack space

#include <bits/stdc++.h>
    void solve(stack<int> &s, int ele)
{
    if (s.empty() || s.top() < ele)
    {
        s.push(ele);
        return;
    }
    int e = s.top();
    s.pop();
    solve(s, ele);
    s.push(e);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int ele = stack.top();
    stack.pop();
    sortStack(stack);
    solve(stack, ele);
}