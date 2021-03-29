/*
 * @lc app=leetcode id=831 lang=cpp
 *
 * [831] Masking Personal Information
 */

// @lc code=start
class Solution {
public:
    string maskPII(string S) {
        if (isPhoneNumber(S)) {
            return maskPhoneNumber(S);
        } else {
            return maskEmail(S);
        }
    }

    bool isPhoneNumber(const string& s) {
        for (char c : s) {
            switch (c) {
            case '+':
            case '-':
            case '(':
            case ')':
            case ' ':
                break;
            default:
                if (c < '0' || c >'9') return false;
            }
        }
        return true;
    }

    string maskEmail(const string& s) {
        string res;
        bool inname = true;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
            case '@':
                inname = false; // fall-over!
            case '.':
                res.push_back(c);
                break;
            default:
                if (i == 0) {
                    res.push_back(tolower(c));
                    res += "*****";
                }
                else if (inname && s[i + 1] == '@') res.push_back(tolower(c));
                else if (inname) {}
                else res.push_back(tolower(c));
            }
        }
        return res;
    }

    string maskPhoneNumber(const string& s) {
        string res;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c < '0' || c > '9') continue;
            if (res.size() < 4) {
                res.push_back(c);
            } else {
                if (res.size() % 4 == 0) {
                    res.push_back('-');
                }
                res.push_back('*');
            }
        }
        if (res.size() >= 14) res.push_back('+');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

