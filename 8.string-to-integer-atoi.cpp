/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int cur = 0;
        for (; cur < n && str[cur] == ' '; cur++);
        int sign = 1;
        if (cur < n && (str[cur] == '-' || str[cur] == '+')) {
            sign = str[cur++] == '-' ? -1 : 1;
        }
        long long res = 0;
        for (; cur < n && isdigit(str[cur]); cur++) {
            res *= 10;
            res += (str[cur] - '0');
            if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
        }
        return res * sign;
    }
};
// @lc code=end

