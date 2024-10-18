class Solution {
private:
    int solve(int index, int curror, int& maxior, vector<int>& nums) {
        // base case
        if (index == nums.size()) {
            if (curror == maxior) {
                return 1;
            }
            return 0;
        }

        // take
        int take = solve(index + 1, curror | nums[index], maxior, nums);

        // not take
        int nottake = solve(index + 1, curror, maxior, nums);

        return take + nottake;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxior = 0;

        for (auto it : nums) {
            maxior |= it;
        }

        return solve(0, 0, maxior, nums);
    }
};