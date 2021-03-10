/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> pow(nums.size(), 1);
        const int MOD = 1000000007;
        for (int i = 1; i < nums.size(); i++) {
            pow[i] = pow[i - 1] * 2 % MOD;
        }
        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++) {
            while (i <= j && nums[i] + nums[j] > target) j--;
            if (j < i) break;
            res = (res + pow[j - i]) % MOD;
        }
        return res;
    }
};
// @lc code=end

