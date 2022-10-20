/*34. Find First and Last Position of Element in Sorted Array
Medium
14.4K
353
Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        int first = -1, last = -1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                j = mid - 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                i = mid + 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};