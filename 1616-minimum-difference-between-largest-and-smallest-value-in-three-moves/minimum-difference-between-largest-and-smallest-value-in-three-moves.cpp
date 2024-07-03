class Solution {
public:
    int minDifference(vector<int>& nums) {
        int size = nums.size();
        if (size < 4) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int choice1 = nums[size - 1] - nums[3];
        int choice2 = nums[size - 2] - nums[2];
        int choice3 = nums[size - 3] - nums[1];
        int choice4 = nums[size - 4] - nums[0];

        return min({choice1, choice2, choice3, choice4});
    }
};