/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; i++) {
            int d = data[i];
            int bytes = 0;
            if ((d & 0x80) == 0x0) continue;
            else if ((d & 0xE0) == 0xC0) bytes = 2;
            else if ((d & 0xF0) == 0xE0) bytes = 3;
            else if ((d & 0xF8) == 0xF0) bytes = 4;
            else return false;
            for (int j = 1; j < bytes; j++) {
                i++;
                if (i >= n || (data[i] & 0xC0) != 0x80) return false;
            }
        }
        return true;
    }
};
// @lc code=end

