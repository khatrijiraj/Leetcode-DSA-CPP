class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }

        map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        sort(nums.begin(), nums.end());

        for (int num : nums) {
            if (mpp[num] > 0) {
                for (int i = 0; i < k; ++i) {
                    if (mpp[num + i] < 1) {
                        return false;
                    }
                    mpp[num + i]--;
                }
            }
        }

        return true;
    }
};