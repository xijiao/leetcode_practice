/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k) return false;
        int n = nums.size(), subsum = sum / k;
        vector<bool> used(n);
        return BackTracing(nums, k, subsum, 0, 0, used);
    }

    bool BackTracing(vector<int>& nums, int k, int subsum, int start, int cursubsum, vector<bool>& used) {
        if (k == 0) return true;
        if (cursubsum == subsum) return BackTracing(nums, k - 1, subsum, 0, 0, used);
        for (int i = start; i < nums.size(); i++) {
            if (used[i] || nums[i] + cursubsum > subsum) continue;
            used[i] = true;
            if (BackTracing(nums, k, subsum, i + 1, cursubsum + nums[i], used)) return true;
            used[i] = false;
        }
        return false;
    }
};
// @lc code=end

