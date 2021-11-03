/*
 * @lc app=leetcode id=1958 lang=cpp
 *
 * [1958] Check if Move is Legal
 */

// @lc code=start
class Solution
{
    static constexpr int DIRS[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

public:
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
    {
        if (board[rMove][cMove] != '.')
            return false;
        board[rMove][cMove] = color;
        return check(board, rMove, cMove, color);
    }

    bool check(vector<vector<char>> &board, int rMove, int cMove, int color)
    {
        for (int i = 0; i < 8; i++)
        {
            bool metMiddle = false;
            for (int nextR = rMove + DIRS[i][0], nextC = cMove + DIRS[i][1];; nextR += DIRS[i][0], nextC += DIRS[i][1])
            {
                //cout << nextR << " " << nextC << endl;
                if (isAbroad(board, nextR, nextC) || board[nextR][nextC] == '.')
                {
                    break;
                }
                else if (board[nextR][nextC] == color)
                {
                    if (metMiddle)
                        return true;
                    else
                        break;
                }
                else
                {
                    metMiddle = true;
                }
            }
        }
        return false;
    }

    bool isAbroad(vector<vector<char>> &board, int r, int c)
    {
        return r < 0 || c < 0 || r >= board.size() || c >= board[0].size();
    }
};
// @lc code=end
