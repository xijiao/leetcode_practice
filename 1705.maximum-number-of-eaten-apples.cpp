/*
 * @lc app=leetcode id=1705 lang=cpp
 *
 * [1705] Maximum Number of Eaten Apples
 */

// @lc code=start
class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    map<int, int> M;  // rot date -> count
    int n = apples.size(), ateApples = 0;
    for (int day = 0;; day++) {
      if (M.empty() && day >= n) break;
      if (day < n && apples[day] > 0) M[day + days[day]] += apples[day];
      for (; !M.empty() && M.begin()->first <= day; M.erase(M.begin()))
        ;
      if (!M.empty()) {
        M.begin()->second--;
        if (M.begin()->second == 0) M.erase(M.begin());
        ateApples++;
      }
    }
    return ateApples;
  }
};
// @lc code=end
