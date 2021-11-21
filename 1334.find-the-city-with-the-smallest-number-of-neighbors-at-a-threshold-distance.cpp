/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold
 * Distance
 */

// @lc code=start
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dp(n, vector<int>(n, 10001));
    for (vector<int>& edge : edges) {
      dp[edge[0]][edge[1]] = dp[edge[1]][edge[0]] = edge[2];
    }
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    int ans = 0, smallest = 10001;
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j < n; ++j) {
        if (dp[i][j] <= distanceThreshold) {
          ++count;
        }
      }
      if (count <= smallest) {
        ans = i;
        smallest = count;
      }
    }
    return ans;
  }
};
// @lc code=end
