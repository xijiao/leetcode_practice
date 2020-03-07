/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int res = 1;
        bitset<256> set(false);
        int former = 0;
        set.set(s[0]);
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (set.test(c)) {
                while (s[former] != c) {
                    set.reset(s[former++]);
                }
                former++;
            } else {
                set.set(c);
                res = max(res, i - former + 1);
            }
        }
        return res;
    }
};
// @lc code=end

