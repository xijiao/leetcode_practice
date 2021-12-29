/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> M;
    for (string& email : emails) M.insert(simplify(email));
    return M.size();
  }
  string simplify(string& email) {
    int pos = email.find('@');
    stringstream ss;
    for (char c : email) {
      if (c == '+' || c == '@')
        break;
      else if (c == '.')
        continue;
      ss << c;
    }
    ss << email.substr(pos);
    return ss.str();
  }
};
// @lc code=end
