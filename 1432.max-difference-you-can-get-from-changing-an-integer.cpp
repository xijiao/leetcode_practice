/*
 * @lc app=leetcode id=1432 lang=cpp
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 */

// @lc code=start
class Solution {
public:
    int maxDiff(int num) {
        int leftdigit = getLeftDigit(num);
        int secondChoiceA = getSecondLeftDigit(num, leftdigit, 0);
        int secondChoiceB = getSecondLeftDigit(num, leftdigit, 9);
        int a = leftdigit != 1 ? replaceDigit(num, leftdigit, 1) : replaceDigit(num, secondChoiceA, 0);
        int b = leftdigit != 9 ? replaceDigit(num, leftdigit, 9) : replaceDigit(num, secondChoiceB, 9);
        //cout << a << " " << b << endl;
        return b - a;
    }

    int getLeftDigit(int n) {
        int res = 0;
        for (; n; n /= 10) {
            res = n % 10;
        }
        return res;
    }

    int getSecondLeftDigit(int n, int except1, int except2) {
        int res = 0;
        for (; n >= 10; n /= 10) {
            int v = n % 10;
            if (v != except1 && v != except2) {
                res = v;
            }
        }
        return res;
    }

    int replaceDigit(int n, int from, int to) {
        int res = 0, muliplier = 1;
        for (; n; n /= 10, muliplier *= 10) {
            int cur = n % 10;
            if (cur == from) {
                res += to * muliplier;
            } else {
                res += cur * muliplier;
            }
        }
        return res;
    }
};
// @lc code=end

