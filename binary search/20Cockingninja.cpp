// love babbar 15 lacture
bool isPossible(int mid, vector<int> &rank, int n, int m)
{

    int dishCount = 0;

    for (int i = 0; i < n; i++)
    {
        int totalTime = rank[i];
        int x = 2;
        while (totalTime <= mid)
        {
            totalTime += x * rank[i];
            dishCount++;
            x++;
        }
        if (dishCount >= m)
        {
            return true;
        }
    }

    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    int s = 0;
    int n = rank.size();
    int max = rank[n - 1];
    int e = (m * (m + 1) / 2) * max;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {

        if (isPossible(mid, rank, n, m))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}