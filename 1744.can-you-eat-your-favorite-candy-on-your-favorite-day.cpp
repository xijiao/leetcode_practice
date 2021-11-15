/*
 * @lc app=leetcode id=1744 lang=cpp
 *
 * [1744] Can You Eat Your Favorite Candy on Your Favorite Day?
 */

// @lc code=start
class Solution {
 public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    vector<long long> C(candiesCount.size());
    C[0] = candiesCount[0];
    for (int i = 1; i < candiesCount.size(); i++) {
      C[i] = C[i - 1] + candiesCount[i];
    }

    vector<bool> res(queries.size());
    for (int i = 0; i < res.size(); i++) {
      int favType = queries[i][0];
      int favDay = queries[i][1];
      long long dailyCap = queries[i][2];

      long long preCount = favType > 0 ? C[favType - 1] : 0;
      long long totalCount = C[favType];
      res[i] = totalCount > favDay && preCount < ((favDay + 1) * dailyCap);
    }
    return res;
  }
};
// @lc code=end
