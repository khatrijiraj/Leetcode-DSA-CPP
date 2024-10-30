class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);
        int maxi = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) {
                maxi = max(maxi, LIS[i] + LDS[i] - 1);
            }
        }

        return n - maxi;
    }
};
