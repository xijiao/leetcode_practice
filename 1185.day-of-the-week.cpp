/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */

// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        time_t now = 0;
        time(&now);
        struct tm sttm = *localtime(&now);
        sttm.tm_year = year - 1900;
        sttm.tm_mon = month - 1;
        sttm.tm_mday = day;
        time_t then = mktime(&sttm);
        sttm = *localtime(&then);
        const char* weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return weekday[sttm.tm_wday];
    }
};
// @lc code=end

