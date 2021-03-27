/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            if (hasEvenDigits(n)) res++;
        }
        return res;
    }

    bool hasEvenDigits(int n) {
        int digits = 0;
        for (; n; n /= 10) digits++;
        return digits % 2 == 0;
    }
};
// @lc code=end

