class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>>& visited) {
        int row = grid.size();
        int col = grid[0].size();

        if (i >= row || i < 0 || j >= col || j < 0 || visited[i][j] == 1 ||
            grid[i][j] == 0) {
            return;
        }

        visited[i][j] = 1;

        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }

    int numberofislands(vector<vector<int>>& grid, int row, int col) {
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        int islands = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    dfs(grid, i, j, visited);
                    islands++;
                }
            }
        }
        return islands;
    }

    bool disconnected(vector<vector<int>>& grid, int row, int col) {
        return numberofislands(grid, row, col) != 1;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if (disconnected(grid, row, col)) {
            return 0;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (disconnected(grid, row, col)) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};