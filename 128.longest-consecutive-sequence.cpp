/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;
        while (!set.empty()) {
            int n = *set.begin();
            set.erase(set.begin());
            int prev = n - 1, next = n + 1;
            for (; set.find(prev) != set.end(); prev--) set.erase(prev);
            for (; set.find(next) != set.end(); next++) set.erase(next);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
// @lc code=end

