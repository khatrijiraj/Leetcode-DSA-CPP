class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};

        int maxi = 0;

        for (auto it : directions) {
            int newrow = row + it.first;
            int newcol = col + it.second;

            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
                grid[newrow][newcol] > grid[row][col]) {
                maxi = max(maxi, 1 + dfs(newrow, newcol, grid, dp));
            }
        }

        dp[row][col] = maxi;
        return dp[row][col];
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int maxi = 0;

        for (int i = 0; i < m; i++) {
            maxi = max(maxi, dfs(i, 0, grid, dp));
        }

        return maxi;
    }
};