/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 */

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;
            if (tx > ty) {
                if (ty == sy && (tx - sx) % ty == 0) return true;
                tx %= ty;
            } else {
                if (tx == sx && (ty - sy) % tx == 0) return true;
                ty %= tx;
            }
        }
        return false;
    }
};
// @lc code=end

