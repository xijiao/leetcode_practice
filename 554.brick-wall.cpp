/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> count;
        for (const auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                count[sum] ++;
            }
        }
        int maxSum = 0;
        for (const auto& n : count) {
            maxSum = max(maxSum, n.second);
        }
        return wall.size() - maxSum;
    }
};
// @lc code=end

