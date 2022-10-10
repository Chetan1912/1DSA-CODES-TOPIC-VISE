
oblem Statement
Sample Input 1 :
2
[()]{}{[()()]()}
[(])
Sample Output 1 :
Balanced
Not Balanced
Explanation Of The Sample Input 1 :
In TestCase 1 there is always an opening brace before a closing brace i.e ‘{
    ‘ before ‘}’, ‘(‘ before ‘)’, ‘[‘ before ‘]’.

In TestCase 2 there is closing brace for ‘[‘ i.e. ‘]’ before closing brace for ‘(‘ i.e. ‘)’. The balanced sequence should be ‘[()]’.
bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {

        char ch = expression[i];

        // if opening bracket, stack push
        // if close bracket, stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.size();i++){
    if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        stack.push(s[i]);
    else
    {
        if (!stack.empty())
        {
            if (s[i] == ')' and stack.top() != '(')
                return false;
            if (s[i] == '}' and stack.top() != '{')
                return false;
            if (s[i] == ']' and stack.top() != '[')
                return false;
            stack.pop();
        }

        else
            return false;
    }}
        return stack.empty();
}
}
;