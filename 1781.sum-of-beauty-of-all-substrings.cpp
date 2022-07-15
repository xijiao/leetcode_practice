/*
 * @lc app=leetcode id=1781 lang=cpp
 *
 * [1781] Sum of Beauty of All Substrings
 */

// @lc code=start
class Solution {
 public:
  int beautySum(string s) {
    int sum = 0;
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      memset(count, 0, sizeof(count));
      for (int j = i; j < s.size(); j++) {
        count[s[j] - 'a']++;
        sum += calcBeauty(count);
      }
    }
    return sum;
  }

  int calcBeauty(int count[26]) {
    int minCount = INT_MAX, maxCount = INT_MIN;
    for (int i = 0; i < 26; i++) {
      if (count[i] == 0) continue;
      minCount = min(minCount, count[i]);
      maxCount = max(maxCount, count[i]);
    }
    return maxCount - minCount;
  }
};
// @lc code=end
