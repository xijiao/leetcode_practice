/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        int maxv = piles[0];
        for (int i = 1; i < n; i++) {
            maxv = max(piles[i], maxv);
        }
        int lo = 1, hi = maxv;
        while (lo < hi) {
            int k = lo + (hi - lo) / 2;
            if (canEatAll(piles, k, H)) {
                hi = k;
            } else {
                lo = k + 1;
            }
        }
        return lo;
    }

    bool canEatAll(vector<int>& piles, int k, int H) {
        cout << k << endl;
        for (int v : piles) {
            int t = (v + k -  1) / k;
            if (t > H) return false;
            H -= t;
        }
        return true;
    }
};
// @lc code=end

