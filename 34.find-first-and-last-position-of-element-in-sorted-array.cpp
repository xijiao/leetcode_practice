/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        int a = bsearch_l(nums, target, 0, n - 1);
        if (a == -1)
            return {-1, -1};
        int b = bsearch_r(nums, target, 0, n - 1);
        return {a, b};
    }

    int bsearch_l(vector<int> &nums, int target, int l, int r)
    {
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return nums[l] == target ? l : -1;
    }

    int bsearch_r(vector<int> &nums, int target, int l, int r)
    {
        while (l < r)
        {
            int m = (l + r + 1) / 2;
            if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
// @lc code=end
