/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
      int ans = 0;
      for (int i = left; i <= right; ++i) {
        if (isPrime(countBits(i))) ans++;
      }
      return ans;
    }

    int countBits(int n) {
      int ans = 0;
      while (n) {
        ans++;
        n &= (n - 1);
      }
      return ans;
    }
    int isPrime(int n) {
      switch (n) {
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
        case 23:
          return true;
        default:
          return false;
      }
    }
};
// @lc code=end

