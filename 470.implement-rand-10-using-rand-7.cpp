/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int v = 7 * (rand7() - 1) + rand7() - 1;
            if (v < 40) return v % 10 + 1;
        }
    }
};
// @lc code=end

