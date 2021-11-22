/*
 * @lc app=leetcode id=1850 lang=cpp
 *
 * [1850] Minimum Adjacent Swaps to Reach the Kth Smallest Number
 */

// @lc code=start
class Solution {
public:
    int getMinSwaps(string num, int k) {
      int n = num.size();
      string permu = num;
      while (--k >= 0) next_permutation(permu.begin(), permu.end());
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (num[i] == permu[i]) continue;
        int j = i + 1;
        for (; j < n; j++) {
          if (num[i] == permu[j]) break;
        }
        ans += (j - i);
        for (int k = j; k > i; --k) {
          swap(permu[k], permu[k - 1]);
        }
      }
      return ans;
    }
};
// @lc code=end

