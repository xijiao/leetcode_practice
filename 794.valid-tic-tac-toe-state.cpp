/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countx = count(board, 'X');
        int counto = count(board, 'O');
        if (countx < counto || countx > counto + 1) return false;
        bool winerx = winner(board, 'X'), winero = winner(board, 'O');
        if (winerx && winero) return false;
        if (winerx && countx != counto + 1) return false;
        if (winero && countx != counto) return false;
        return true;
    }

    int count(vector<string>& board, char player) {
        int res = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == player) res++;
            }
        }
        return res;
    }

    bool winner(vector<string>& board, char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
        return false;
    }

};
// @lc code=end

