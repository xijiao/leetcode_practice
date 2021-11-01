/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        vector<unordered_map<int, int>> M(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)nums[i] - nums[j];
                if (diff < INT_MIN || diff > INT_MAX)
                    continue;

                int count = M[j][(int)diff];
                res += count;
                M[i][(int)diff] += (count + 1);
            }
        }
        return res;
    }
};
// @lc code=end
