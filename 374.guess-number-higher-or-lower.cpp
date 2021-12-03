/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    int l = 1, r = n;
    while (l < r) {
      int m = ((long long)l + r) / 2;
      int res = guess(m);
      if (res < 0)
        r = m - 1;
      else if (res > 0)
        l = m + 1;
      else
        return m;
    }
    return l;
  }
};
// @lc code=end
