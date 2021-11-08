/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> res(n);
    stack<int> st;  // num
    unordered_map<int, int> M;
    for (int i = 0; i < n; i++) {
      M[nums1[i]] = i;
    }
    for (int i = m - 1; i >= 0; i--) {
      int v = nums2[i];
      while (!st.empty() && st.top() <= v) {
        st.pop();
      }
      if (M.count(v)) {
        res[M[v]] = st.empty() ? -1 : st.top();
      }
      st.push(v);
    }
    return res;
  }
};
// @lc code=end
