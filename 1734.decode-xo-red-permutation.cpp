/*
 * @lc app=leetcode id=1734 lang=cpp
 *
 * [1734] Decode XORed Permutation
 */

// @lc code=start
class Solution {
 public:
  vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    vector<int> ans;
    ans.resize(n);
    for (int i = 1; i <= n; i++) {
      ans[0] ^= i;
    }
    for (int i = 1; i < encoded.size(); i += 2) {
      ans[0] ^= encoded[i];
    }

    for (int i = 1; i < ans.size(); i++) {
      ans[i] = ans[i - 1] ^ encoded[i - 1];
    }
    return ans;
  }
};
// @lc code=end
