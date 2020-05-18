/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 */

// @lc code=start
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> cache;
        for (int num : nums) cache[num]++;

        for (auto it = cache.begin(); it != cache.end(); ++it) {
            if (!it->second) continue;
            int count = it->second;
            auto it2 = it;
            int i = 0;
            for (; it2 != cache.end() && i < k; ++it2, i++) {
                if (it2->first != it->first + i) return false;
                if (it2->second < count) return false;
                it2->second -= count;
            }
            if (it2 == cache.end() && i != k) return false;
        }
        return true;
    }
};
// @lc code=end

