/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution {
    static constexpr int DIRS[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        for (char c : instructions) {
            switch (c) {
                case 'G':
                    x += DIRS[dir][0];
                    y += DIRS[dir][1];
                    break;
                case 'L':
                    dir = (dir + 1) % 4;
                    break;
                case 'R':
                    dir = (dir - 1 + 4) % 4;
                    break;
            }
        }
        return x == 0 && y == 0 || dir != 0;
    }
};
// @lc code=end

