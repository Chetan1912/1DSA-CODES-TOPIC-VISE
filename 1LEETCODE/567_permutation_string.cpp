// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

//                                                                                  In other words,
//     return true if one of s1's permutations is the substring of s2.

//            Example 1 :

//     Input : s1 = "ab",
//             s2 = "eidbaooo" Output : true Explanation : s2 contains one permutation of s1("ba").Example 2 :

//     Input : s1 = "ab",
//             s2 = "eidboaoo" Output : false
class Solution
{
private:
    bool checkeqle(int ar1[26], int ar2[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (ar1[i] != ar2[i])
            {
                return 0;
            }
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int a1count[26] = {0};
        int a2count[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a';
            a1count[index]++;
        }
        // traverse s2 string in window of size s1 length and compare
        int i = 0;
        int windowsize = s1.length();
        // running for the first window
        while (i < windowsize && i < s2.length())
        {
            int index = s2[i] - 'a';
            a2count[index]++;
            i++;
        }
        if (checkeqle(a1count, a2count))
        {
            return true;
        }
        // now making the other windows
        while (i < s2.length())
        {
            int newidx = s2[i] - 'a';
            // adding the index in the count 2
            a2count[newidx]++;
            // erase old 🧓 indx;
            int oldidx = s2[i - windowsize] - 'a';
            a2count[oldidx]--;
            i++;
            if (checkeqle(a1count, a2count))
            {
                return 1;
            }
        }
        return 0;
    }
};