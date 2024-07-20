class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int rowsize = rowSum.size();
        int colsize = colSum.size();

        vector<vector<int>> result(rowsize, vector<int>(colsize, 0));

        int i = 0, j = 0;

        while (i < rowsize && j < colsize) {
            result[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= result[i][j];
            colSum[j] -= result[i][j];

            if (rowSum[i] == 0) {
                i++;
            }

            if (colSum[j] == 0) {
                j++;
            }
        }

        return result;
    }
};