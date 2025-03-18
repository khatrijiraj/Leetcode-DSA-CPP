/*
class Solution {
private:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int steal = nums[i] + solve(nums, i + 2, dp);
        int skip = solve(nums, i + 1, dp);

        return dp[i] = max(steal, skip);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, 0, dp);
    }
};
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = max stolen money till ith house
        vector<int> dp(n + 1, 0);

        // no house nothing stolen, i = 0;
        dp[0] = 0;

        // only house then only one stolen, i = 1
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            // we have only two choices to make for each house either steal or
            // skip from a house

            // if we steal then current + house before adjacent maximum
            int stolen = nums[i - 1] + dp[i - 2];

            // if we are not stealing from current house then max from earlier
            // house encountered
            int skip = dp[i - 1];

            // storing the maximum possibility
            dp[i] = max(stolen, skip);
        }

        return dp[n];
    }
};