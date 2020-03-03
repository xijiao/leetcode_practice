/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start

#include <string>

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        helper(res, S, 0);
        return res;
    }

    bool helper(vector<int>& res, const string& S, int start) {
        if (start == S.size() && res.size() > 2) return true;

        long long v = 0;
        for (int i = start; i < S.size(); i++) {
            if (S[start] == '0' && i > start) break;
            v = v * 10 + (S[i] - '0');
            if (v > numeric_limits<int>::max()) break;
            if (res.size() >= 2 && (long long)res[res.size() - 1] + res[res.size() - 2] < v) {
                break;
            }
            if (res.size() < 2 || (long long)res[res.size() - 1] + res[res.size() - 2] == v) {
                res.push_back(v);
                if (helper(res, S, i + 1)) return true;
                res.pop_back();
            }
        }
        return false;
    }
};
// @lc code=end

