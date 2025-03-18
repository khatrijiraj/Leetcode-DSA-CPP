class Solution {
private:
    int solve(int n, int curr, vector<int>& dp) {
        if (curr > n) {
            return 0;
        }

        if (curr == n) {
            return 1;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        return dp[curr] = solve(n, curr + 1, dp) + solve(n, curr + 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, 0, dp);
    }
};