/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> m;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            m[position[i]] = speed[i];
        }
        int fleets = 0;
        long long cp = -1;
        long long cs = -1;
        for (const auto& p : m) {
            long long position = p.first;
            long long speed = p.second;
            if (cp < 0 || (target - position) * cs > (target - cp) * speed) {
                fleets ++;
                cp = position;
                cs = speed;
            }
        }
        return fleets;
    }
};
// @lc code=end

