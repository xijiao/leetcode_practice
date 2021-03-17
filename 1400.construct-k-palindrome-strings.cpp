/*
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        int oddcount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2) oddcount++;
        }
        return oddcount <= k;
    }
};
// @lc code=end

