/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
    int left[3] = {0}; // $5, $10, $20
public:
    bool lemonadeChange(vector<int>& bills) {
        for (int bill : bills) {
            if (!getChange(bill - 5)) return false;
            putBill(bill);
        }
        return true;
    }

    int bill2index(int bill) {
        switch (bill) {
            case 5: return 0;
            case 10: return 1;
            case 20: return 2;
        }
        return -1;
    }

    void putBill(int bill) {
        left[bill2index(bill)]++;
    }

    bool getChange(int change) {
        if (change >= 20) {
            int count = min(change / 20, left[2]);
            left[2] -= count;
            change -= count * 20;
        }
        if (change >= 10) {
            int count = min(change / 10, left[1]);
            left[1] -= count;
            change -= count * 10;
        }
        if (change >= 5) {
            int count = min(change / 5, left[0]);
            left[0] -= count;
            change -= count * 5;
        }
        return change == 0;
    }
};
// @lc code=end

