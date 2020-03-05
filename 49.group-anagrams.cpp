/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       unordered_map<string, int> sorted_map;
       for (const string& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            auto it = sorted_map.find(sorted);
            if (it == sorted_map.end()) {
               res.push_back(vector<string>());
               it = sorted_map.insert(make_pair(sorted, res.size() - 1)).first;
            }
            res[it->second].push_back(s);
        }
       return res;
    }
};
// @lc code=end

