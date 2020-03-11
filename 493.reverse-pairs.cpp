/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        multiset<int> s;
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int n = nums[i];
            res += distance(s.begin(), s.lower_bound((n >> 1) + (n & 1)));
            s.insert(n);
        }
        return res;
    }
};
// @lc code=end

