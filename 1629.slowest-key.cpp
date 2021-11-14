/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */

// @lc code=start
class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    char key = 0;
    int longest = 0, lasttime = 0;
    for (int i = 0; i < releaseTimes.size(); i++) {
      int time = releaseTimes[i];
      char curkey = keysPressed[i];
      int duration = time - lasttime;
      if (duration > longest) {
        longest = duration;
        key = curkey;
      } else if (duration == longest) {
        key = max(key, curkey);
      }
      lasttime = time;
    }
    return key;
  }
};
// @lc code=end
