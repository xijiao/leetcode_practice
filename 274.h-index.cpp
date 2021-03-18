/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count[1001] = {0};
        for (int c : citations) count[c]++;
        int sum = 0;
        for (int i = 1000; i >= 0; i--) {
            sum += count[i];
            if (sum >= i) return i; 
        }
        return 0;
    }
};
// @lc code=end

