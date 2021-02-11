/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
            if (cur_sum < 0) cur_sum = 0;
        }

        return max_sum;
    }
};

/*
// Divide and Conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
public:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) return numeric_limits<int>::min();
        if (l == r) return nums[l];

        int m = (l + r) / 2;
        int maxl = maxSubArray(nums, l, m - 1);
        int maxr = maxSubArray(nums, m + 1, r);

        int maxsubl = 0, maxsubr = 0;
        for (int i = m - 1, sum = 0; i >= 0; i--) {
            sum += nums[i];
            maxsubl = max(maxsubl, sum);
        }
        for (int i = m + 1, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxsubr = max(maxsubr, sum);
        }
        
        return max(max(maxl, maxr), nums[m] + maxsubl + maxsubr);
    }
};
*/

// @lc code=end

