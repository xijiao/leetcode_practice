/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    int ans = -1;
    for (int i = 0; i < strs.size(); ++i) {
      bool isUS = true;
      for (int j = 0; j < strs.size(); ++j) {
        if (i == j) continue;
        if (isSubsequence(strs[i], strs[j])) {
          isUS = false;
          break;
        }
      }
      if (isUS) {
        ans = max(ans, (int)strs[i].size());
      }
    }
    return ans;
  }

  // if A is a subsequence of B, return true.
  bool isSubsequence(const string& A, const string& B) {
    int i = 0;
    for (char b : B) {
      if (i < A.size() && A[i] == b) i++;
    }
    return i == A.size();
  }
};
// @lc code=end
