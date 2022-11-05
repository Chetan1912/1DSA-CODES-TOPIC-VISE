// approach 1
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (auto &i : nums)
            i = i * i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
// approach 2(two pointer)
class Solution
{
public:
    vector sortedSquares(vector &nums)
    {

        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--)
        {

            if (abs(nums[left]) > nums[right])
            {
                ans[i] = nums[left] * nums[left];
                left++;
            }
            else
            {
                ans[i] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};