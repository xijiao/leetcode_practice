/*
 * @lc app=leetcode id=906 lang=cpp
 *
 * [906] Super Palindromes
 */

// @lc code=start
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long long l = stoll(L), r = stoll(R);
        vector<long long> q = {0,1,2,3,4,5,6,7,8,9};
        long long p = pow(r, 0.25);
        for (long long i = 1; i < 10000 && i < p; i++) {
            string a = to_string(i), b = a; reverse(b.begin(), b.end());
            q.push_back(stoll(a + b));
            for (int j = 0; j < 10; j++) {
                q.push_back(stoll(a + to_string(q[j]) + b));
            }
        }
        int res = 0;
        for (long long v : q) {
            v *= v;
            if (v < l || v > r) continue;
            if (isP(v)) res++;
        }
        return res;
    }

    bool isP(long long v) {
        long long u = 0;
        while (v > u) {
            u *= 10;
            u += v % 10;
            if (u == v) return true;
            v /= 10;
            if (u == v) return true;
        }
        return false;
    }
};
// @lc code=end

