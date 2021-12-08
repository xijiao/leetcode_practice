/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> M;
    for (int i = 0; i < list1.size(); i++) {
      M[list1[i]] = i;
    }
    int indexsum = INT_MAX;
    vector<string> ans;
    for (int index2 = 0; index2 < list2.size(); index2++) {
      if (!M.count(list2[index2])) continue;
      int index1 = M[list2[index2]];
      if (index1 + index2 == indexsum) {
        ans.push_back(list2[index2]);
      } else if (index1 + index2 < indexsum) {
        ans.clear();
        ans.push_back(list2[index2]);
        indexsum = index1 + index2;
      }
    }
    return ans;
  }
};
// @lc code=end
