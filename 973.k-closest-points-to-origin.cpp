/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> M;
        for (auto& point: points) {
            int dis = point[0] * point[0] + point[1] * point[1];
            M.insert({dis, point});
            if (M.size() > k) M.erase(prev(M.end(), 1));
        }
        vector<vector<int>> res;
        for (auto& node : M) {
            res.push_back(node.second);
        }
        return res;
    }
};
// @lc code=end

