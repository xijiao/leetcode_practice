/*
 * @lc app=leetcode id=691 lang=cpp
 *
 * [691] Stickers to Spell Word
 */

// @lc code=start
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if (target.size() == 0) return 0;
        string tar(26, '\0');
        unordered_map<string, int> cache;
        cache[tar] = 0;
        for (char s : target) {
            tar[s - 'a'] ++;
        }
        return dfs(stickers, tar, cache);
    }

    int dfs(vector<string>& stickers, string& tar,
            unordered_map<string, int>& cache) {
        int res = -1;
        for (const string& s: stickers) {
            string ltar = tar;
            bool found = false;
            for (char c : s) {
                if (ltar[c - 'a'] > 0) {
                    found = true;
                    ltar[c - 'a'] --;
                }
            }
            if (!found) continue;
            auto it = cache.find(ltar);
            if (it == cache.end()) {
                it = cache.emplace(ltar, dfs(stickers, ltar, cache)).first;
            }
            int subres = it->second;
            if (subres >= 0) {
                res = res < 0 ? 1 + subres : min(res, 1 + subres);
            }
        }
        return res;
    }
};
// @lc code=end

