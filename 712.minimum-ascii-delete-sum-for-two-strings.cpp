/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        unordered_map<int, int> cache;
        cache[s1.size() << 16 | s2.size()] = 0;
        return dfs(s1, s2, cache, 0, 0);
    }

    int dfs(const string& s1, const string& s2,
            unordered_map<int, int>& cache, int i, int j) {
        auto it = cache.find(i << 16 | j);
        if (it != cache.end()) return it->second;

        int res = 0;
        if (i == s1.size()) {
            res = s2[j] + dfs(s1, s2, cache, i, j + 1);
        } else if (j == s2.size()) {
            res = s1[i] + dfs(s1, s2, cache, i + 1, j);
        } else if (s1[i] == s2[j]) {
            res = dfs(s1, s2, cache, i + 1, j + 1);
        } else {
            res = min(s1[i] + dfs(s1, s2, cache, i + 1, j),
                    s2[j] + dfs(s1, s2, cache, i, j + 1));
        }
        cache[i << 16 | j] = res;
        return res;
    }
};
// @lc code=end

