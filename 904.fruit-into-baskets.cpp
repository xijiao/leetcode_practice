/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> picked;
    int n = fruits.size(), count = 0, ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      picked[fruits[r]]++;
      count++;
      if (picked.size() <= 2) {
        ans = max(ans, count);
      } else {
        while (picked.size() > 2) {
          if (--picked[fruits[l]] == 0) {
            picked.erase(fruits[l]);
          }
          ++l;
          --count;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
