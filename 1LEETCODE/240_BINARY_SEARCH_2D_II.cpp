// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example 1:

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int colind = col - 1;
        int rowind = 0;
        while (colind >= 0 && rowind < row)
        {
            int ele = matrix[rowind][colind];
            if (ele == target)
            {
                return 1;
            }
            if (ele < target)
            {
                rowind++;
            }
            else
            {
                colind--;
            }
        }
        return 0;
    }
};