/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> stat;
        for (int i : arr) stat[i]++;
        unordered_set<int> stat2;
        for (const auto& node : stat) {
            if (stat2.find(node.second) != stat2.end()) return false;
            stat2.emplace(node.second);
        }
        return true;
    }
};
// @lc code=end

