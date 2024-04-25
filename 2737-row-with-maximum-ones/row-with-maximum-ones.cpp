class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index, max = -1;
        int row = mat.size();
        int col = mat[0].size();

        for (int i = 0; i < row; i++) {
            sort(mat[i].begin(), mat[i].end());
            int low = 0;
            int high = mat[i].size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (max < col - low) {
                max = col - low;
                index = i;
            }
        }
        return {index, max};
    }
};