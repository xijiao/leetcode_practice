/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') continue;
            for (char j = 'a'; j <= 'z'; j++) {
                if (i > 0 && s[i - 1] == j) continue;
                if (i < s.size() - 1 && s[i + 1] == j) continue;
                s[i] = j;
                break;
            }
        }
        return s;
    }
};
// @lc code=end

