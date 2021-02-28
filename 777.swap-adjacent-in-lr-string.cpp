/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();

        for (int i = 0, j = 0; i < n || j < n; ) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (i == n && j == n) return true;
            if (i == n || j == n) return false;
            if (start[i] != end[j]) return false;
            if (start[i] == 'R' && i > j) return false;
            if (start[i] == 'L' && i < j) return false;
            i++;
            j++;
        }
        return true;
    }
};
// @lc code=end

