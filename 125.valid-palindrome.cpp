/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <cstring>

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int i = 0, j = s.size() - 1;
        for (; i < s.size() && !isalnum(s[i]); i++);
        for (; j >= 0 && !isalnum(s[j]); j--);
        while (i < j) {
            if (tolower(s[i]) != tolower(s[j])) return false;
            for (i++; i < s.size() && !isalnum(s[i]); i++);
            for (j--; j >= 0 && !isalnum(s[j]); j--);
        }
        return true;
    }
};
// @lc code=end

