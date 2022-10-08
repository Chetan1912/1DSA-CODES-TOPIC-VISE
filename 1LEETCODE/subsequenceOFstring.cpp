// mple Input 1 : 1 abc
//     Sample Output 1 : a ab abc ac b bc c
//                           Explanation Of Sample Input 1 : All possible subsequences of abc are :
// “a”, “b”, “c”, “ab”, “bc”, “ac”, “abc”
//                                                               Sample Input 2 : 1 bbb
//                                                                   Sample Output 2 : b b b bb bb bb bbb
void solve(string str, string output, int index, vector<string> &ans)
{

    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    // exclude
    solve(str, output, index + 1, ans);
    // include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}
