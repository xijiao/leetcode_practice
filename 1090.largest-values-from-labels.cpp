/*
 * @lc app=leetcode id=1090 lang=cpp
 *
 * [1090] Largest Values From Labels
 */

// @lc code=start
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        multimap<int, int, std::greater<int>> value_label;
        unordered_map<int, int> used_labels;
        for (int i = 0; i < values.size(); i++) {
            value_label.insert({values[i], labels[i]});
        }
        int res = 0;
        int num = 0;
        for (auto it = value_label.begin(); num < num_wanted && it != value_label.end(); ++it) {
            if (used_labels[it->second] >= use_limit) continue;
            res += it->first;
            used_labels[it->second]++;
            ++num;
        }
        return res;
    }
};
// @lc code=end

