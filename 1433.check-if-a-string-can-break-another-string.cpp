/*
 * @lc app=leetcode id=1433 lang=cpp
 *
 * [1433] Check If a String Can Break Another String
 */

// @lc code=start
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int count1[26] = {0}, count2[26] = {0};
        for (char c : s1) count1[c - 'a']++;
        for (char c : s2) count2[c - 'a']++;
        enum {EQ, BT, LT};
        int prestate = EQ;
        int curcount1 = 0, curcount2 = 0;
        for (int i = 0; i < 26; i++) {
            curcount1 += count1[i];
            curcount2 += count2[i];
            int nextstate = EQ;
            if (curcount1 > curcount2) nextstate = BT;
            else if (curcount1 < curcount2) nextstate = LT;
            if (nextstate != prestate && prestate != EQ && nextstate != EQ) return false;
            if (nextstate!= EQ) prestate = nextstate;
        }
        return true;
    }
};
// @lc code=end

