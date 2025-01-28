class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row,
            int col) {
        int rows = grid.size();
        int cols = grid[0].size();

        int total = 0;

        queue<pair<int, int>> qt;
        qt.push({row, col});
        visited[row][col] = true;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!qt.empty()) {
            int x = qt.front().first;
            int y = qt.front().second;

            qt.pop();

            total += grid[x][y];

            for (int i = 0; i < 4; i++) {
                int newx = x + dir[i].first;
                int newy = y + dir[i].second;

                if (newx >= 0 && newx < rows && newy >= 0 && newy < cols &&
                    grid[newx][newy] && !visited[newx][newy]) {
                    qt.push({newx, newy});
                    visited[newx][newy] = true;
                }
            }
        }

        return total;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxi = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    maxi = max(maxi, dfs(grid, visited, i, j));
                }
            }
        }

        return maxi;
    }
};
