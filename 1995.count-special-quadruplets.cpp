/*
 * @lc app=leetcode id=1995 lang=cpp
 *
 * [1995] Count Special Quadruplets
 */

// @lc code=start
class Solution
{
public:
    // n^3
    // 211/211 cases passed (168 ms)
    // Your runtime beats 43.96 % of cpp submissions
    // Your memory usage beats 5.02 % of cpp submissions (50.7 MB)
    // int countQuadruplets(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     vector<unordered_map<int, int>> sumof2(n), sumof3(n);
    //     int res = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (sumof3[j].count(nums[i]))
    //             {
    //                 res += sumof3[j][nums[i]];
    //             }
    //             for (auto &node : sumof2[j])
    //             {
    //                 sumof3[i][node.first + nums[i]] += node.second;
    //             }
    //             sumof2[i][nums[j] + nums[i]]++;
    //         }
    //     }
    //     return res;

    int countQuadruplets(vector<int> &nums)
    {
        int n = nums.size(), res = 0;
        unordered_map<int, int> M;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (M.count(nums[j] - nums[i]))
                {
                    res += M[nums[j] - nums[i]];
                }
            }
            for (int k = 0; k < i; k++)
            {
                M[nums[i] + nums[k]]++;
            }
        }
        return res;
    }
};
// @lc code=end
