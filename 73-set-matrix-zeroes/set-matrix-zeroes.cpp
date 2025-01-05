class Solution {
    /* void markrow(int i, vector<vector<int>>& matrix, int n) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markcol(int j, vector<vector<int>>& matrix, int m) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    } */

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        /* BRUTE APPROACH
        TC:- O((M * N) * (M + N)) + O(M * N)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    markrow(i, matrix, n);
                    markcol(j, matrix, m);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
        */

        /* BETTER APROACH
        TC- O(2 * (M * N))
        */
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};