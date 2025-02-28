class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int row = 0; row <= len1; row++) {
            dp[row][0] = row;
        }

        for (int col = 0; col <= len2; col++) {
            dp[0][col] = col;
        }

        for (int row = 1; row <= len1; row++) {
            for (int col = 1; col <= len2; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string result = "";
        int row = len1, col = len2;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                result += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                result += str1[row - 1];
                row--;
            } else {
                result += str2[col - 1];
                col--;
            }
        }

        while (row > 0) {
            result += str1[row - 1];
            row--;
        }

        while (col > 0) {
            result += str2[col - 1];
            col--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
