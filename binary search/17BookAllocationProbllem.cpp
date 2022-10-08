https : // www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
#include <vector>
        bool
        isPossible(int n, int m, vector<int> time, long long int mid)
{
    int day = 1;
    long long int reqTime = 0;
    for (int i = 0; i < m; i++)
    {
        if (reqTime + time[i] <= mid)
        {
            reqTime += time[i];
        }
        else
        {
            day++;
            if (day > n || time[i] > mid)
            {
                return false;
            }
            reqTime = time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long start = 0;
    long long totalTime = 0;
    for (int i = 0; i < time.size(); i++)
    {
        totalTime += time[i];
    }
    long long end = totalTime;
    long long ans = -1;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossible(n, m, time, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
Problem Statement
    Problem Statement
