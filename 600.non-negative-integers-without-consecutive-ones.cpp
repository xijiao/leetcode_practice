/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
class Solution {
    unordered_map<int, int> cache;
public:
    int findIntegers(int num) {
        // 000
        // 001
        // 010
        // 011
        // 100
        // 101
        // 110
        // 111
        if (num == 0) return 1;
        if (num == 1) return 2;
        if (cache.count(num)) return cache[num];
        int firstbit = 31;
        for (; firstbit >= 1; firstbit--) {
            if (num & (1 << firstbit)) break;
        }
        int res;
        if (num & (1 << (firstbit - 1))) {
            res = findIntegers((1 << firstbit) | ((1 << (firstbit - 1)) - 1));
        } else {
            res = findIntegers(num & ~(1 << firstbit)) +
                findIntegers((1 << firstbit) - 1);
        }
        cache[num] = res;
        return res;
    }
};
// @lc code=end

