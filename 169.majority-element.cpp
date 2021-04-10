/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count[32] = {0};
        for (int n : nums) {
            for (int i = 0; i < 32; i++) {
                if ((unsigned)n & (1U << i)) count[i]++;
            }
        }
        unsigned res = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] > nums.size() / 2) res |= (1U << i);
        }
        return (int)res;
    }
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> count;
    //     for (int n : nums) count[n]++;
    //     for (auto& kv : count) {
    //         if (kv.second > nums.size() / 2) return kv.first;
    //     }
    //     return -1;
    // }
};
// @lc code=end

