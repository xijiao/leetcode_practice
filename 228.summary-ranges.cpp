/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
    vector<string> res;
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return res;
        int low = nums[0], up = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            if (n == up + 1) {
                up = n;
            } else {
                appendRange(low, up);
                low = up = n;
            }
        }
        appendRange(low, up);
        return res;
    }

    void appendRange(int low, int up) {
        string v;
        if (low != up) v = to_string(low) + "->" + to_string(up);
        else v = to_string(low);
        res.push_back(v);
    }
};
// @lc code=end

