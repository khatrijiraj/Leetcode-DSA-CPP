class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> qt;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    qt.push({i, j});
                }
            }
        }

        vector<int> dirs = {-1, 0, 1, 0, -1};

        while (!qt.empty()) {
            auto [x, y] = qt.front();
            qt.pop();

            for (int d = 0; d < 4; d++) {
                int newX = x + dirs[d];
                int newY = y + dirs[d + 1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    height[newX][newY] == -1) {
                    height[newX][newY] = height[x][y] + 1;
                    qt.push({newX, newY});
                }
            }
        }

        return height;
    }
};