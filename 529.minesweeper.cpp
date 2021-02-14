/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    static constexpr int DIRS[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    bool inBounds(vector<vector<char>>& board, int x, int y) {
        int n = board.size(), m = board[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        reveal(board, click[0], click[1]);
        return board;
    }

    void reveal(vector<vector<char>>& board, int x, int y) {
        if (!inBounds(board, x, y) || board[x][y] != 'E') return;

        int mines = calcNearMine(board, x, y);
        if (mines == 0) {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i++) {
                reveal(board, x + DIRS[i][0], y + DIRS[i][1]);
            }
        } else {
            board[x][y] = '0' + mines;
        }
    }

    int calcNearMine(vector<vector<char>>& board, int x, int y) {
        int res = 0;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 8; i++) {
            int x1 = x + DIRS[i][0];
            int y1 = y + DIRS[i][1];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m ||
                    board[x1][y1] != 'M') {
                continue;
            }
            res++;
        }
        return res;
    }
};
// @lc code=end

