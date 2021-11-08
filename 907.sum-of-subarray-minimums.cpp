/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int res = 0, n = arr.size();
    stack<pair<int, int>> st1, st2;  // min, count
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
      int v = arr[i];
      int count = 1;
      while (!st1.empty() && st1.top().first >= v) {
        count += st1.top().second;
        st1.pop();
      }
      st1.push({v, count});
      left[i] = count;
    }
    for (int i = n - 1; i >= 0; i--) {
      int v = arr[i];
      int count = 1;
      while (!st2.empty() && st2.top().first > v) {
        count += st2.top().second;
        st2.pop();
      }
      st2.push({v, count});
      right[i] = count;
    }

    for (int i = 0; i < n; i++) {
      res = (res + (long)arr[i] * left[i] * right[i]) % MOD;
    }
    return res;
  }
};
// @lc code=end
