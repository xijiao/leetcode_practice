/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int curvalue = arr[0];
        int curstart = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != curvalue) {
                curvalue = arr[i];
                curstart = i;
                continue;
            } else if ((i - curstart + 1) * 4 > arr.size()) {
                return curvalue;
            }
        }
        return -1;
    }
};
// @lc code=end

