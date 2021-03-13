/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
    vector<int> _data;
public:
    Solution(vector<int>& nums) {
        srand(time(nullptr));
        _data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(_data);
        for (int i = 0; i < res.size() - 1; i++) {
            int j = rand() % (res.size() - i) + i;
            swap(res[i], res[j]); 
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

