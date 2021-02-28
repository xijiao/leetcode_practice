/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; n > 0 && i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) continue;
            if (hasAdjacent(flowerbed, i)) continue;
            flowerbed[i] = 1;
            n--;
        }
        return n == 0;
    }

    bool hasAdjacent(vector<int>& flowerbed, int i) {
        if (i > 0 && flowerbed[i - 1] == 1) return true;
        if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1) return true;
        return false;
    }
};
// @lc code=end

