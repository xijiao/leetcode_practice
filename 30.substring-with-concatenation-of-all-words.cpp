/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty() || words[0].empty()) return {};
        int n = s.size(), m = words.size(), w = words[0].size();
        vector<bool> used(m, false);
        vector<int> res;
        for (int i = 0; i <= n - m * w; i++) {
            dfs(s, words, n, m, w, used, res, i);
        }
        return res;
    }

    bool dfs(const string& s, const vector<string>& words,
            int n, int m, int w,
            vector<bool>& used, vector<int>& res, int index) {

        bool has_left = false;
        for (int i = 0; i < m; i ++) {
            if (used[i]) continue;
            has_left = true;
            if (!compareStr(s, words[i], index)) continue;
            used[i] = true;
            if (dfs(s, words, n, m, w, used, res, index + w)) {
                used[i] = false;
                return true;
            }
            used[i] = false;
        }
        if (!has_left) {
            res.push_back(index - m * w);
            return true;
        }
        return false;
    }

    bool compareStr(const string& s, const string& sub, int index) {
        if (index + sub.size() > s.size()) return false;
        for (int i = 0; i < sub.size(); i++) {
            if (s[index + i] != sub[i]) return false;
        }
        return true;
    }
};
// @lc code=end

