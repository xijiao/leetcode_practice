/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        string mul(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int v = (num1[i] - '0') * (num2[j] - '0') +
                        (mul[i + j + 1] - '0') + carry;
                carry = v / 10;
                mul[i + j + 1] = (v % 10) + '0';
            }
            if (carry > 0) {
                mul[i] = carry + '0';
            }
        }

        int k = 0;
        for (; k < mul.size() && mul[k] == '0'; k++);
        return k == mul.size() ? "0" : mul.substr(k, mul.size() - k);
    }
};
// @lc code=end

