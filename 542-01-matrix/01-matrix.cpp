class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<pair<int, int>, int>> qt;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    qt.push({{i, j}, 0});
                    distance[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (!qt.empty()) {
            int x = qt.front().first.first;
            int y = qt.front().first.second;
            int dist = qt.front().second;

            qt.pop();

            for (auto& it : directions) {
                int newx = x + it.first;
                int newy = y + it.second;

                if (newx >= 0 && newx < row && newy >= 0 && newy < col &&
                    visited[newx][newy] != 1) {
                    distance[newx][newy] = dist + 1;
                    visited[newx][newy] = 1;
                    qt.push({{newx, newy}, dist + 1});
                }
            }
        }

        return distance;
    }
};