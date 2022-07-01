/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */

// @lc code=start
class Solution {
 public:
  string reformatNumber(string number) {
    number = removeOtherChar(number);
    vector<string> groups = reGroup(number);
    return join(groups, "-");
  }

  string removeOtherChar(const string& number) {
    stringstream ss;
    for (char c : number) {
      if (isdigit(c)) ss << c;
    }
    return ss.str();
  }

  vector<string> reGroup(const string& number) {
    vector<string> res;
    for (int cur = 0;;) {
      int left = number.size() - cur;
      if (left > 4) {
        res.push_back(number.substr(cur, 3));
        cur += 3;
      } else if (left == 4) {
        res.push_back(number.substr(cur, 2));
        res.push_back(number.substr(cur + 2, 2));
        break;
      } else {
        res.push_back(number.substr(cur));
        break;
      }
    }
    return res;
  }

  string join(vector<string> groups, string delim) {
    stringstream ss;
    for (int i = 0; i < groups.size(); i++) {
      if (i != 0) ss << "-";
      ss << groups[i];
    }
    return ss.str();
  }
};
// @lc code=end
