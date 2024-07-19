class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        int rowminiMAX = INT_MIN;
        for (int row = 0; row < rowsize; row++) {
            int rowmini = INT_MAX;
            for (int col = 0; col < colsize; col++) {
                rowmini = min(rowmini, matrix[row][col]);
            }
            rowminiMAX = max(rowminiMAX, rowmini);
        }

        int colmaxiMIN = INT_MAX;
        for (int col = 0; col < colsize; col++) {
            int colmaxi = INT_MIN;
            for (int row = 0; row < rowsize; row++) {
                colmaxi = max(matrix[row][col], colmaxi);
            }
            colmaxiMIN = min(colmaxiMIN, colmaxi);
        }

        vector<int> result;

        if (rowminiMAX == colmaxiMIN) {
            result.push_back(rowminiMAX);
            return result;
        } else {
            return result;
        }
    }
};