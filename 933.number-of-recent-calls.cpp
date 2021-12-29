/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter {
  queue<int> Q;

 public:
  RecentCounter() {}

  int ping(int t) {
    Q.push(t);
    while (t - Q.front() > 3000) {
      Q.pop();
    }
    return Q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
