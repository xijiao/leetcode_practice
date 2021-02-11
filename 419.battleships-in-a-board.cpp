/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 'X') continue;
                if ((i == 0 || board[i - 1][j] != 'X') &&
                    (j == 0 || board[i][j - 1] != 'X')) {
                        res++;
                }
            }    
        }
        return res;
    }
};
// @lc code=end

