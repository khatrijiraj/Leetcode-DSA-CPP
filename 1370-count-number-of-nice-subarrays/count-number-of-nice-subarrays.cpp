class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> oddArray(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            oddArray[i] = nums[i] % 2;
        }

        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int current = 0;
        int count = 0;

        for (int it : oddArray) {
            current += it;

            if (mpp.find(current - k) != mpp.end()) {
                count += mpp[current - k];
            }

            mpp[current]++;
        }

        return count;
    }
};