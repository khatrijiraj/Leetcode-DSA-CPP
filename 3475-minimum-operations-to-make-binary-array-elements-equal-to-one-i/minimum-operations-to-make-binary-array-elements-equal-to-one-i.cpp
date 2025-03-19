class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                k++;
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
            }
        }

        for (auto it : nums) {
            if (it == 0) {
                return -1;
            }
        }

        return k;
    }
};