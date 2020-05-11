/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i)) res.push_back(i);
        }
        return res;
    }

    bool isSelfDividingNumber(int v) {
        for (int p = v, t = p % 10; p; p /= 10, t = p % 10) {
            if (t == 0) return false;
            if (v % t) return false;
        }
        return true;
    }
};
// @lc code=end

