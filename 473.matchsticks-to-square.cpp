/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int totalLength = 0;
        for (int l : matchsticks) totalLength += l;
        if (totalLength % 4) return false;
        int sideLength = totalLength / 4;
        for (int l : matchsticks) if (l > sideLength) return false;
        int used = 0;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> curSideLength(4, 0);
        return dfs(matchsticks, curSideLength, 0, sideLength);
    }

    bool dfs(vector<int>& matchsticks, vector<int>& curSideLength, int index, int sideLength) {
        if (index == matchsticks.size()) return true;
        for (int i = 0; i < 4; ++i) {
            if (curSideLength[i] == sideLength) continue;
            bool seenBefore = false;
            for (int j = i - 1; j >= 0; --j) {
                if (curSideLength[i] == curSideLength[j]) seenBefore = true;
            }
            if (seenBefore) continue;

            if (matchsticks[index] + curSideLength[i] > sideLength) continue;
            curSideLength[i] += matchsticks[index];
            if (dfs(matchsticks, curSideLength, index + 1, sideLength)) return true;
            curSideLength[i] -= matchsticks[index];
        }
        return false;
    }
};
// Accepted (12 ms)
/*
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int totalLength = 0;
        for (int l : matchsticks) totalLength += l;
        if (totalLength % 4) return false;
        int sideLength = totalLength / 4;
        for (int l : matchsticks) if (l > sideLength) return false;
        int used = 0;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, 0, 0, 0, used, sideLength);
    }

    bool dfs(vector<int>& matchsticks, int side, int index,
            int curlength, int used, int sideLength) {
        bool res = false;
        if (side == 4) return true;
        if (curlength == sideLength) return dfs(matchsticks, side + 1, 0, 0, used, sideLength);

        for (int i = index; i < matchsticks.size(); i++) {
            if (used & (1 << i) || matchsticks[i] + curlength > sideLength) {
                continue;
            }
            if (dfs(matchsticks, side, i + 1, matchsticks[i] + curlength, used | (1 << i), sideLength)) return true;
        }
        return false;
    }
};
*/
// @lc code=end

