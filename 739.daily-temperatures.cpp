/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> st;  // temp, count
    int n = temperatures.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
      int v = 0;
      while (!st.empty() && st.top().first <= temperatures[i]) {
        v += st.top().second;
        st.pop();
      }
      if (!st.empty() && st.top().first > temperatures[i]) {
        res[i] = v + 1;
      }
      st.push({temperatures[i], v + 1});
    }
    return res;
  }
};
// @lc code=end
