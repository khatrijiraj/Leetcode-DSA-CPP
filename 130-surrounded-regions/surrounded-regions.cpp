class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board[0].size() || visited[row][col] == 1 ||
            board[row][col] == 'X') {
            return;
        }

        visited[row][col] = 1;

        dfs(row - 1, col, visited, board);
        dfs(row, col + 1, visited, board);
        dfs(row + 1, col, visited, board);
        dfs(row, col - 1, visited, board);
    }

public:
    void solve(vector<vector<char>>& board) {

        if (board.empty()) {
            return;
        }

        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < col; i++) {
            // first row
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, visited, board);
            }
            // last row
            if (board[row - 1][i] == 'O' && !visited[row - 1][i]) {
                dfs(row - 1, i, visited, board);
            }
        }

        for (int i = 0; i < row; i++) {
            // first col
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, visited, board);
            }
            // last col
            if (board[i][col - 1] == 'O' && !visited[i][col - 1]) {
                dfs(i, col - 1, visited, board);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && visited[i][j] != 1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};