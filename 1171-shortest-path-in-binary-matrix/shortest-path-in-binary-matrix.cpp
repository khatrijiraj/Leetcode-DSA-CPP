class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        vector<pair<int, int>> directions = {{0, 1},   {-1, 1}, {-1, 0},
                                             {-1, -1}, {0, -1}, {1, -1},
                                             {1, 0},   {1, 1}};

        queue<pair<int, int>> qt;
        qt.push({0, 0});
        grid[0][0] = 1;

        while (!qt.empty()) {
            auto [x, y] = qt.front();
            int dist = grid[x][y];
            qt.pop();

            if (x == n - 1 && y == n - 1) {
                return dist;
            }

            for (auto& it : directions) {
                int newx = x + it.first;
                int newy = y + it.second;

                if (newx >= 0 && newx < n && newy >= 0 && newy < n &&
                    grid[newx][newy] == 0) {
                    qt.push({newx, newy});
                    grid[newx][newy] = dist + 1;
                }
            }
        }

        return -1;
    }
};