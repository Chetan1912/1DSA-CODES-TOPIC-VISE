class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int temp;

        // MACKING THE transport

        for (int R = 0; R < row; R++)

        {
            for (int C = 0; C < R; C++)
            {
                swap(matrix[C][R], matrix[R][C]);
            }
        }
        // REVERS THE ROW;
        for (int R = 0; R < row; R++)

        {
            int left = 0;
            int right = matrix.size() - 1;
            while (left < right)
            {
                swap(matrix[R][left], matrix[R][right]);
                left++;
                right--;
            }
        }
    }
};