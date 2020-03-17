/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        for (int i = 0; candies; i++) {
            int v = min(candies, i + 1);
            candies -= v;
            res[i % num_people] += v;
        }
        return res;
    }
};
// @lc code=end

