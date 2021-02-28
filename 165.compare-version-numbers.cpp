/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        char _;
        int v1 = 0, v2 = 0;
        for (; !ss1.eof() || !ss2.eof();) {
            v1 = 0;
            v2 = 0;
            ss1 >> v1;
            ss2 >> v2;
            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
            ss1 >> _;
            ss2 >> _;
        }
        return 0;
    }
};
// @lc code=end

