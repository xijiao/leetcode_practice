/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
 public:
  string fractionToDecimal(long numerator, long denominator) {
    if (numerator == 0) return "0";
    stringstream ss;
    if (numerator < 0 && denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    } else if (numerator < 0) {
      ss << "-";
      numerator = -numerator;
    } else if (denominator < 0) {
      ss << "-";
      denominator = -denominator;
    }
    long left = numerator / denominator;
    numerator %= denominator;
    ss << left;
    if (numerator) ss << ".";
    unordered_map<int, int> M;  // v -> index
    int loopindex = -1;
    while (numerator) {
      numerator *= 10;
      if (M.count(numerator)) {
        loopindex = M[numerator];
        break;
      }
      M[numerator] = ss.tellp();
      int v = numerator / denominator;
      ss << v;
      numerator %= denominator;
    }
    if (loopindex == -1) {
      return ss.str();
    } else {
      ss << ")";
      string tmp = ss.str();
      return tmp.substr(0, loopindex) + "(" + tmp.substr(loopindex);
    }
  }
};
// @lc code=end
