/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
class Solution {
 public:
  // Time Limit Exceeded
  //   int maximumGain(string s, int x, int y) {
  //     unordered_map<string, int> dp;
  //     int res = 0;
  //     int start = 0;
  //     for (int i = 0; i <= s.size(); i++) {
  //       if (i == s.size() || s[i] != 'a' && s[i] != 'b') {
  //         res += helper(s.substr(start, i - start), x, y, dp);
  //         start = i + 1;
  //       }
  //     }
  //     return res;
  //   }

  //   int helper(string s, int x, int y, unordered_map<string, int>& dp) {
  //     if (dp.count(s)) return dp[s];
  //     int res = 0;
  //     int pos = s.find("ab");
  //     if (pos != string::npos) {
  //       res =
  //           max(res, helper(s.substr(0, pos) + s.substr(pos + 2), x, y, dp) +
  //           x);
  //     }
  //     pos = s.find("ba");
  //     if (pos != string::npos) {
  //       res =
  //           max(res, helper(s.substr(0, pos) + s.substr(pos + 2), x, y, dp) +
  //           y);
  //     }
  //     return dp[s] = res;
  //   }

  // Greedy
  int maximumGain(string s, int x, int y) {
    string a = "ab", b = "ba";
    if (y > x) swap(a, b), swap(x, y);
    return remove(s, a, x) + remove(s, b, y);
  }

  int remove(string& s, string& v, int p) {
    int res = 0;
    int i = 0;
    for (int j = 0; j < s.size();) {
      if (j < s.size() - 1 && s[j] == v[0] && s[j + 1] == v[1]) {
        j += 2;
        res += p;
      } else if (i > 0 && s[i - 1] == v[0] && s[j] == v[1]) {
        i--;
        j++;
        res += p;
      } else {
        s[i++] = s[j++];
      }
    }
    s.resize(i);
    return res;
  }
};
// @lc code=end
