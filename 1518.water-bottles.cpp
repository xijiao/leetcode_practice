/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int fullcount = numBottles;
        int emptycount = 0;
        int res = 0;
        for (; fullcount;) {
            res += fullcount;
            emptycount += fullcount;
            fullcount = 0;
            fullcount += emptycount / numExchange;
            emptycount %= numExchange;
        }
        return res;
    }
};
// @lc code=end

