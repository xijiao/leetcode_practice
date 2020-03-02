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
        if (S.size() < 3) return {};
        for (int i = 1; i < S.size() - 1 && i < 10; i++) {
            if (i > 1 && S[0] == '0') break;
            for (int j = i + 1; j < S.size() && j - i < 10; j++) {
                if (j == i + 2 && S[i] == '0') break;
                vector<int> res = trySplit(S, i, j);
                if (res.size() > 0) return res;
            }
        }

        return {};
    }

    vector<int> trySplit(const string& S, int i, int j) {
        //cout << i << " " << j << endl;
        long long a, b;
        a = std::stoll(S.substr(0, i));
        b = std::stoll(S.substr(i, j - i));
        if (a > numeric_limits<int>::max() ||
                b > numeric_limits<int>::max()) {
            return {};
        }
        //cout << a << " " << b << endl;
        int left_start = j;
        vector<int> res = {a, b};
        for (; left_start < S.size();) {
            int n = a + b;
            if (n < 0) return {};
            a = b;
            b = n;
            string sn = to_string(n);
            if (sn.size() + left_start > S.size() ||
                    !compareSubStr(S, sn, left_start)) {
                return {};
            }
            res.push_back(n);
            left_start += sn.size();
        }
        return res;
    }

    bool compareSubStr(const string& s, const string& sub, int start) {
        if (start + sub.size() > s.size()) return false;
        for (int i = 0; i < sub.size() && i < s.size() - start; i++) {
            if (s[start + i] != sub[i]) return false;
        }
        return true;
    }
};
// @lc code=end

