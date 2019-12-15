/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x / 10 == 0) return true;
        if (x % 10 == 0) return false;

        int y = 0;
        for (;x > y;) {
            y = y * 10 + x % 10;
            if (x == y) return true;
            x /= 10;
            if (x == y) return true;
        }
        return false;
    }
};
// @lc code=end

