/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    const int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 0;
    int r = 0, c = 0;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          r = i;
          c = j;
          break;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int x = r + DIRS[i][0], y = c + DIRS[i][1];
           x >= 0 && y >= 0 && x < 8 && y < 8;
           x += DIRS[i][0], y += DIRS[i][1]) {
        if (board[x][y] == 'p') {
          ans++;
          break;
        } else if (board[x][y] == 'B') {
          break;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
