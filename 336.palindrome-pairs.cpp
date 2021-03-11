/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, vector<int>> M;
        for (int i = 0; i < words.size(); i++) {
            M[words[i]].push_back(i);
        }

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                string l = word.substr(0, j);
                string r = word.substr(j);
                if (isPalindrome(l)) {
                    string r2 = r;
                    reverse(r2.begin(), r2.end());
                    if (M.count(r2)) {
                        for (int t : M[r2]) {
                            if (t != i) res.push_back({t, i});
                        }
                    }
                }
                if (!r.empty() && isPalindrome(r)) {
                    string l2 = l;
                    reverse(l2.begin(), l2.end());
                    if (M.count(l2)) {
                        for (int t : M[l2]) {
                            if (t != i) res.push_back({i, t});
                        }
                    }
                }
            }
        }
        return res;
    }

    bool isPalindrome(const string& s) {
        for (int l = 0, r = s.size() -1; l < r;) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
// @lc code=end

