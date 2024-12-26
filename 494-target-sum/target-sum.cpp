class Solution {
public:
    int solve(vector<int>& nums, int currsum, int index, int target) {
        if (index == nums.size()) {
            if (currsum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        int plus = solve(nums, currsum + nums[index], index + 1, target);
        int minus = solve(nums, currsum - nums[index], index + 1, target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};