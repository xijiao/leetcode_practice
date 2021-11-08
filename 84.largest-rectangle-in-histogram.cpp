/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0, n = heights.size();
    stack<pair<int, int>> st1, st2;  // min, count
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
      int h = heights[i];
      int count = 1;
      while (!st1.empty() && st1.top().first >= h) {
        count += st1.top().second;
        st1.pop();
      }
      st1.push({h, count});
      left[i] = count;
    }
    for (int i = n - 1; i >= 0; i--) {
      int h = heights[i];
      int count = 1;
      while (!st2.empty() && st2.top().first > h) {
        count += st2.top().second;
        st2.pop();
      }
      st2.push({h, count});
      right[i] = count;
    }
    for (int i = 0; i < n; i++) {
      res = max(res, heights[i] * (left[i] + right[i] - 1));
    }
    return res;
  }
};
// @lc code=end
