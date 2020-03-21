/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int is_ny = year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0);
        int doy = 0;
        for (int m = 1; m < month; m++) {
            doy += (monthdays[m - 1] + ((m == 2 && is_ny) ? 1 : 0));
        }
        doy += day;
        return doy;
    }
};
// @lc code=end

