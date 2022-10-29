/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey,
                   string ruleValue) {
    int ans = 0;
    for (const vector<string>& item : items) {
      if (isMatched(item, ruleKey, ruleValue)) ans++;
    }
    return ans;
  }

  bool isMatched(const vector<string>& item, const string& ruleKey,
                 const string& ruleValue) {
    if (ruleKey == "type") {
      return item[0] == ruleValue;
    } else if (ruleKey == "color") {
      return item[1] == ruleValue;
    } else if (ruleKey == "name") {
      return item[2] == ruleValue;
    }
    return false;
  }
};
// @lc code=end
