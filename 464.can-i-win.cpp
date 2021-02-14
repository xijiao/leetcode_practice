/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
class Solution {
    int cache[1<<20] = {};
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }

    bool dfs(int maxChoosableInteger, int desiredTotal, int used) {
        if (desiredTotal == 1) return true;
        if (cache[used]) return cache[used] > 0;

        bool res = false;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (used & (1 << (i - 1))) continue;
            if (i >= desiredTotal) {
                res = true;
                break;
            }
            if (!dfs(maxChoosableInteger, desiredTotal - i, used | (1 << (i - 1)))) {
                res = true;
                break;
            }
        }
        cache[used] = res ? 1 : -1;
        return res;
    }
};
// @lc code=end

