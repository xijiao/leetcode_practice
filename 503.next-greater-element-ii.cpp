/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      int v = nums[i];
      while (!st.empty() && st.top() <= v) {
        st.pop();
      }
      st.push(v);
    }
    for (int i = n - 1; i >= 0; i--) {
      int v = nums[i];
      while (!st.empty() && st.top() <= v) {
        st.pop();
      }
      res[i] = st.empty() ? -1 : st.top();
      st.push(v);
    }
    return res;
  }
};
// @lc code=end
