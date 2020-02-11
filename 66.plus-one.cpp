/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool plus = true;
        for (int i = digits.size() - 1; plus && i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                plus = false;
            } else {
                digits[i] = 0;
            }
        }

        if (plus) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

