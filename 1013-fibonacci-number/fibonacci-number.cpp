class Solution {
    /* private:
        int solve(int n, vector<int>& dp) {
            if (n <= 1) {
                return n;
            }

            if (dp[n] != -1) {
                return dp[n];
            }

            return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        } */

public:
    int fib(int n) {
        /* SIMPLE RECURSION
        TC:- O(2^n)
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
         */

        /* Memoized Recursion:- TOP DOWN APPROACH
        vector<int> dp(n + 1, -1);
        return solve(n, dp); */

        /* BOTTOM UP APPROACH
        TC O(n)
        */

        if (n < 2) {
            return n;
        }

        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};