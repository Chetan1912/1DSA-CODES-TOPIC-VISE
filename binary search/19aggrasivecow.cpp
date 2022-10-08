// lecture 15 love babbar
https : // www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
        bool
        ispossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int lastmaxpos = stalls.size() - 1;
    int maxi = stalls[lastmaxpos]; // for the max value in array;
    int ans = -1;

    int e = maxi;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (ispossible(stalls, k, mid))
        {
            s = mid + 1; // because largest solusion nikalna h
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}