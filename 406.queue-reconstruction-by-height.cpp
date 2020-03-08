/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end());
        for (int right = people.size() - 1; right >= 0;) {
            int left = right;
            while (left > 0 && people[left - 1][0] == people[right][0]) left--;
            for (int i = left; i <= right; i++) {
                res.insert(res.begin() + people[i][1], people[i]);
            }
            right = left - 1;
        }
        return res;
    }
};
// @lc code=end

