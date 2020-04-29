/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0;
        int res = 0;
        for (int n : nums) {
            sum += n;
            if (sum == k) res ++;
            res += m.count(sum - k) ? m[sum - k] : 0;
            m[sum] += 1;
        }
        return res;
    }
};
// @lc code=end

