/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            int count = 0;
            for (int n : nums) {
                count += (n - 1) / m;
            }
            if (count > maxOperations) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
// @lc code=end

