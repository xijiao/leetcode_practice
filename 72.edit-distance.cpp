/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return find(word1, word2, m, n, dp);
    }

    int find(const string& word1, const string& word2, int l, int r, vector<vector<int>>& dp) {
        if (l == 0) return r;
        if (r == 0) return l;
        if (dp[l][r] != -1) return dp[l][r];
        int m = word1.size(), n = word2.size();
        int res = 0;
        if (word1[l - 1] == word2[r - 1]) res = find(word1, word2, l - 1, r - 1, dp);
        else res = min(find(word1, word2, l - 1, r - 1, dp) + 1,
                min(find(word1, word2, l - 1, r, dp) + 1, find(word1, word2, l, r - 1, dp) + 1));
        dp[l][r] = res;
        return res;
    }
};
// @lc code=end

