/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> inNums1, visited;
    for (int n : nums1) {
      inNums1.insert(n);
    }
    vector<int> ans;
    for (int n : nums2) {
      if (!inNums1.count(n)) continue;
      if (visited.count(n)) continue;
      ans.push_back(n);
      visited.insert(n);
    }
    return ans;
  }
};
// @lc code=end
