class Solution {
private:
    long long solve(int i, vector<vector<int>>& questions,
                    vector<long long>& dp) {
        if (i >= questions.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        long long taken =
            questions[i][0] + solve(i + questions[i][1] + 1, questions, dp);
        long long nottaken = solve(i + 1, questions, dp);

        return dp[i] = max(taken, nottaken);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size() + 1, -1);
        return solve(0, questions, dp);
    }
};