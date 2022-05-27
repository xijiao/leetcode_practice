/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size(), res = 0;
    for (int l = -1, r = n, lmax = 0, rmax = 0; l + 1 < r;) {
      if (lmax < rmax) {
        l++;
        lmax = max(height[l], lmax);
        res += max(0, min(lmax, rmax) - height[l]);
      } else {
        r--;
        rmax = max(height[r], rmax);
        res += max(0, min(lmax, rmax) - height[r]);
      }
    }
    return res;
  }
};
// @lc code=end
