/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        for (int i = 2; i < n; i++) {
            if (!isprime[i]) continue;
            for (int j = i * 2; j < n; j += i) {
                isprime[j] = false;
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isprime[i]) res++;
        }
        return res;
    }
};
// @lc code=end

