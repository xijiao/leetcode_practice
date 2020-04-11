/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

// @lc code=start
class Solution {
public:
    int numPrimeArrangements(int n) {
        int primeCount = calcPrimeCount(n);
        long long res = 1;
        for (int i = 2; i <= primeCount; i++) {
            res *= i;
            res %= 1000000007LL;
        }
        for (int i = 2; i <= n - primeCount; i++) {
            res *= i;
            res %= 1000000007LL;
        }
        return res;
    }

    int calcPrimeCount(int n) {
        bitset<101> bs;
        bs.set();
        for (int i = 2; i <= n; i++) {
            if (!bs.test(i)) continue;
            for (int v = i + i; v <= n; v += i) bs.reset(v);
        }
        int res = 0;
        for (int i = 2; i <= n; i++) {
            if (bs.test(i)) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

