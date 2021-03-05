/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 1000 || nums[i] < -1000) continue;
            if (nums[i] % n == 0) continue;

            int cur = ((i + nums[i]) % n + n) % n;
            bool forward = nums[i] > 0;
            int mark = i + 1001;
            nums[i] = mark;
            for (; nums[cur] >= -1000 && nums[cur] <= 1000 && nums[cur] % n != 0;) {
                //cout << cur << " ";
                if (forward != (nums[cur] > 0)) break;
                int tmp = ((cur + nums[cur]) % n + n) % n;
                nums[cur] = mark;
                cur = tmp;
            }
            //cout << endl;
            if (nums[cur] == mark) return true;
        }
        return false;
    }
};
// @lc code=end

