/*
 * @lc app=leetcode id=1563 lang=cpp
 *
 * [1563] Stone Game V
 */

// @lc code=start
class Solution {
 public:
  int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    if (n <= 1) return 0;
    vector<int> sums;
    int sum = 0;
    for (int v : stoneValue) {
      sums.push_back(sum);
      sum += v;
    }
    sums.push_back(sum);

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = helper(sums, 0, n - 1, dp);
    return ans;
  }

  int helper(vector<int>& sums, int left, int right, vector<vector<int>>& dp) {
    if (left >= right) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    int ans = 0;
    for (int mid = left; mid < right; ++mid) {
      int leftsum = sums[mid + 1] - sums[left];
      int rightsum = sums[right + 1] - sums[mid + 1];
      if (leftsum > rightsum) {
        ans = max(ans, rightsum + helper(sums, mid + 1, right, dp));
      } else if (leftsum < rightsum) {
        ans = max(ans, leftsum + helper(sums, left, mid, dp));
      } else {
        ans = max(ans, max(rightsum + helper(sums, mid + 1, right, dp),
                           leftsum + helper(sums, left, mid, dp)));
      }
    }
    return dp[left][right] = ans;
  }
};
// @lc code=end
