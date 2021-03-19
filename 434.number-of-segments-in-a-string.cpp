/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool was_space = true;
        for (char c : s) {
            if (c == ' ') {
                was_space = true;
            } else {
                if (was_space) {
                    res++;
                    was_space = false;
                }
            }
        }
        return res;
    }
};
// @lc code=end

