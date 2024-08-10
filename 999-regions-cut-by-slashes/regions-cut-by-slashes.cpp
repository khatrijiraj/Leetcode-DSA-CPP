class Solution {
private:
    void dfs(vector<vector<int>>& newgrid, int i, int j) {
        int row = newgrid.size();
        int col = newgrid[0].size();

        if (i >= row || i < 0 || j >= col || j < 0 || newgrid[i][j] == 1) {
            return;
        }

        newgrid[i][j] = 1;

        dfs(newgrid, i + 1, j);
        dfs(newgrid, i - 1, j);
        dfs(newgrid, i, j + 1);
        dfs(newgrid, i, j - 1);
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> newgrid(row * 3, vector<int>(col * 3, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '/') {
                    newgrid[i * 3][j * 3 + 2] = 1;
                    newgrid[i * 3 + 1][j * 3 + 1] = 1;
                    newgrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    newgrid[i * 3][j * 3] = 1;
                    newgrid[i * 3 + 1][j * 3 + 1] = 1;
                    newgrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int region = 0;
        for (int i = 0; i < row * 3; i++) {
            for (int j = 0; j < col * 3; j++) {
                if (newgrid[i][j] == 0) {
                    dfs(newgrid, i, j);
                    ++region;
                }
            }
        }
        return region;
    }
};