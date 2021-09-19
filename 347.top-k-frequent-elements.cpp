/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;

        vector<vector<int>> D;
        for (const auto& node : count) {
            D.push_back({node.second, node.first});
        }
        sort(D.begin(), D.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(D[i][1]);
        return res;
    }
};
// @lc code=end

