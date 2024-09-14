class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isvalid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvalid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch || board[i][col] == ch) {
                return false;
            }
        }

        int rowstart = (row / 3) * 3;
        int colstart = (col / 3) * 3;
        for (int i = rowstart; i < rowstart + 3; i++) {
            for (int j = colstart; j < colstart + 3; j++) {
                if (board[i][j] == ch) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};