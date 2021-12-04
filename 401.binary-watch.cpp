/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    dfs(turnedOn, 0, 0, ans);
    // sort(ans.begin(), ans.end());
    return ans;
  }

  void dfs(int turnedOn, int mask, int startbit, vector<string>& ans) {
    if (turnedOn < 0) return;
    if (turnedOn == 0) {
      checkAndAppend(mask, ans);
      return;
    }
    if (turnedOn > 10 - startbit) return;
    dfs(turnedOn, mask, startbit + 1, ans);
    dfs(turnedOn - 1, mask | (1 << startbit), startbit + 1, ans);
  }

  void checkAndAppend(int mask, vector<string>& ans) {
    int hh = mask >> 6;
    int mm = mask & 0x3F;
    if (hh > 11 || mm > 59) return;
    char buf[6];
    snprintf(buf, 6, "%d:%02d", hh, mm);
    ans.push_back(buf);
  }
};
// @lc code=end
