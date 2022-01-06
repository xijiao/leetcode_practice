/*
 * @lc app=leetcode id=1276 lang=cpp
 *
 * [1276] Number of Burgers with No Waste of Ingredients
 */

// @lc code=start
class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (tomatoSlices == 0 && tomatoSlices == 0) return {0, 0};
    if (tomatoSlices < cheeseSlices * 2) return {};
    if (tomatoSlices > cheeseSlices * 4) return {};
    int total = cheeseSlices;
    int jumboDouble = tomatoSlices - total * 2;
    if (jumboDouble % 2 != 0) return {};
    int jumbo = jumboDouble / 2;
    int small = total - jumbo;
    return {jumbo, small};
  }
};
// @lc code=end
