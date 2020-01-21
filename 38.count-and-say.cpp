/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string pre = countAndSay(n - 1);
        stringstream result;
        int count = 1;
        char cur = pre[0];
        for (int i = 1; i < pre.size(); i++) {
            char c = pre[i];
            if (c != cur) {
                result << count << cur;
                count = 1;
                cur = c;
            } else {
                count ++;
            }
        }
        result << count << cur;

        return result.str();
    }
};
// @lc code=end

