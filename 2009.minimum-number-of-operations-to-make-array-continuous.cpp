/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[count++] = nums[i];
            }
        }
        nums.resize(count);

        int l = 0, r = 0, maxRange = 1;
        for (; r < nums.size();)
        {
            if (nums[r] - nums[l] < n)
            {
                maxRange = max(maxRange, r - l + 1);
                r++;
            }
            else
            {
                l++;
            }
        }

        return n - maxRange;
    }
};
// @lc code=end
