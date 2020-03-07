/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> visited(100000);
        for (int c : candies) visited.emplace(c);
        return min(candies.size() / 2, visited.size());
    }
};
// @lc code=end

