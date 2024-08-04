class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> qt;
        int freshoranges = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    qt.push({i, j});
                }
                if (grid[i][j] == 1) {
                    freshoranges++;
                }
            }
        }

        if (freshoranges == 0) {
            return 0;
        }

        int time = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!qt.empty()) {
            int size = qt.size();
            time++;

            for (int i = 0; i < size; i++) {
                auto temp = qt.front();
                qt.pop();

                for (auto dirs : directions) {
                    int newx = temp.first + dirs.first;
                    int newy = temp.second + dirs.second;

                    if (newx >= 0 && newx < row && newy >= 0 && newy < col &&
                        grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        qt.push({newx, newy});
                        freshoranges--;
                    }
                }
            }
        }

        return (freshoranges == 0) ? time - 1 : -1;
    }
};