class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0;
        int end = col * row - 1;
        while (s <= end)
        {
            int mid = s + (end - s) / 2;
            int ele = matrix[mid / col][mid % col];
            if (ele == target)
            {
                return 1;
            }
            if (ele < target)
            {
                s = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return 0;
    }
};