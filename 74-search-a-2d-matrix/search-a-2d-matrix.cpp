class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int mid_row = mid / col;
            int mid_col = mid % col;

            if (matrix[mid_row][mid_col] == target) {
                return true;
            } else if (target > matrix[mid_row][mid_col]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};