/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> D; // distance^2 -> count
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int xi = points[i][0], yi = points[i][1];
                int xj = points[j][0], yj = points[j][1]; 
                int distancesq = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
                res += (D[distancesq] * 2);
                D[distancesq] ++;
            }
        }
        return res;
    }
};
// @lc code=end

