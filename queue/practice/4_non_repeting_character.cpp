// //{ Driver Code Starts
// First non - repeating character in a stream
//                     MediumAccuracy : 51.34 %
//                 Submissions : 64048Points : 4 LampGeek Week 2022 is LIVE !Click Here to View All the Exciting Offers !Given an input stream of A of n characters consisting only of lower case alphabets.The task is to find the first non repeating character,
//     each time a character is inserted to the stream.If there is no such character then append '#' to the answer.

//     Example 1 :

//     Input : A = "aabc" Output : "a#bb" Explanation : For every character first non
//                                                          repeating character is as follow -
//                                                      "a" - first non - repeating character is 'a' "aa" - no non - repeating character so '#' "aab" - first non - repeating character is 'b' "aabc" - first non - repeating character is 'b' Example 2 :

//     Input : A = "zz" Output : "z#" Explanation : For every character first non
//                                                      repeating character is as follow -
//                                                  "z" - first non - repeating character is 'z' "zz" - no non - repeating character so '#'

//                                                  Your Task : You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and returns a string after processing the input stream.

//                                                              Expected Time Complexity : O(26 * n) Expected Space Complexity : O(26)

//                                                                                                                                   Constraints : 1 <=
//                 n <= 105

//                          View Bookmarked Problems
//                              Company Tags
//                                  Topic Tags
//                                      Related Courses
//                                          Related Interview Experiences
//                                              If you are facing any issue on this page.Please let us know.Output Window
//                        Problem Solved Successfully
//                      Test Cases Passed : 305 /
//                          305 Total Points Scored : 4 / 4 Your Total Score : 26 Total Time Taken : 0.19 Your Accuracy : 100 %
//                          Attempts No. :

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        map<char, int> con;
        string ans = "";
        queue<char> q;
        for (int i = 0; i < A.length(); i++)
        {
            char c = A[i];
            q.push(c);
            con[c]++;
            while (!q.empty())
            {
                if (con[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends