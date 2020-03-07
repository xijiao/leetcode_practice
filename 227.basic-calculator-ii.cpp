/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stringstream ss("+" + s + "+");
        int cur = 0, total = 0;
        char op;
        while (ss >> op) {
            if (op == '-' || op == '+') {
                total += cur;
                ss >> cur;
                cur *= op == '-' ? -1 : 1;
            } else {
                int n;
                ss >> n;
                if (op == '*') {
                    cur *= n;
                } else {
                    cur /= n;
                }
            }
        }
        return total;
    }
};
// @lc code=end

