/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 0, hi = m * n + 1;
        while (lo < hi) {
            int c = lo + (hi - lo) / 2;
            if (equalOrBigger(m, n, k, c)) hi = c;
            else lo = c + 1;
        }
        return lo;
    }

    bool equalOrBigger(int m, int n, int k, int c) {
        int total = 0;
        for (int i = 1; i <= m; i++) {
            total += min(n, c / i);
        }
        return total >= k;
    }
};
// @lc code=end

