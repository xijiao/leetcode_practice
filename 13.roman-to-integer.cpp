/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
                case ('M'): {
                    res += 1000;
                    break;
                }
                case ('D'): {
                    res += 500;
                    break;
                }
                case ('C'): {
                    if (i < s.size() - 1 && s[i + 1] == 'D') {
                        res += 400;
                        i++;
                    } else if (i < s.size() - 1 && s[i + 1] == 'M') {
                        res += 900;
                        i++;
                    } else {
                        res += 100;
                    }
                    break;
                }
                case ('L'): {
                    res += 50;
                    break;
                }
                case ('X'): {
                    if (i < s.size() - 1 && s[i + 1] == 'L') {
                        res += 40;
                        i++;
                    } else if (i < s.size() - 1 && s[i + 1] == 'C') {
                        res += 90;
                        i++;
                    } else {
                        res += 10;
                    }
                    break;
                }
                case ('V'): {
                    res += 5;
                    break;
                }
                case ('I'): {
                    if (i < s.size() - 1 && s[i + 1] == 'V') {
                        res += 4;
                        i++;
                    } else if (i < s.size() - 1 && s[i + 1] == 'X') {
                        res += 9;
                        i++;
                    } else {
                        res += 1;
                    }
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

