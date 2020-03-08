/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bitset<100001> bs;
        int asum = 0, bsum = 0;
        for (int i = 0; i < A.size(); i++) {
            asum += A[i];
            bs.set(A[i]);
        }
        for (int i = 0; i < B.size(); i++) {
            bsum += B[i];
        }
        int sub = (bsum - asum) / 2;
        for (int b : B) {
            int a = b - sub;
            if(a >= 1 && a <= 100000 && bs.test(a)) return {a, b};
        }
        return {}; // never
    }
};
// @lc code=end

