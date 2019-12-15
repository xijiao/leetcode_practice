/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        int len = strs[0].size();
        auto& firststr = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            auto& str = strs[i];
            len = min(len, (int)str.size());
            for (int j = 0; j < len; j++) {
                if (firststr[j] != str[j]) {
                    len = j;
                    break;
                }
            }
            if (len == 0) {
                return "";
            }
        }
        return firststr.substr(0, len);
    }
};
// @lc code=end

