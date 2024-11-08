class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxXor = (1 << maximumBit) - 1;
        int currentXor = 0;
        vector<int> result(nums.size());
        for (int num : nums) {
            currentXor ^= num;
        }
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = maxXor ^ currentXor;
            currentXor ^= nums[nums.size() - 1 - i];
        }
        return result;
    }
};
