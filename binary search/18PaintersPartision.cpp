// proclem no 98 in code studio
https : // www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
\bool ispossible(vector<int> board, int n, int mid)
{
    int length = 0;
    int painter = 1;
    for (int i = 0; i < board.size(); i++)
    {
        if (length + board[i] <= mid)
        {
            length += board[i];
        }
        else
        {
            painter++;
            if (painter > n || board[i] > mid)
            {
                return false;
            }
            length = board[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int ans = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        ans = ans + boards[i];
    }
    int e = ans;
    ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (ispossible(boards, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}