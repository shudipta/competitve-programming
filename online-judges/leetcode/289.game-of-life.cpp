/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
    int R[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int C[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveCnt = 0;
                for (int k = 0; k < 8; k++) {
                    int ii = i + R[k];
                    int jj = j + C[k];
                    liveCnt += ii >= 0 && ii < n && jj >= 0 && jj < m &&
                             (board[ii][jj] > 3 ? 0 : board[ii][jj] > 1 ? 1 : board[ii][jj]);
                }
                if (board[i][j])
                    board[i][j] = (liveCnt == 2 || liveCnt == 3) ? 2 : 3;
                else
                    board[i][j] = (liveCnt == 3) ? 4 : 5;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = board[i][j] == 2 || board[i][j] == 4;
            }
        }
    }
};
// @lc code=end

