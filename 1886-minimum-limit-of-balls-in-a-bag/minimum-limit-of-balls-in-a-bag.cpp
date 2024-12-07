class Solution {
    bool ispossible(vector<int>& nums, int maxi, int mid) {
        int totalops = 0;
        for (auto it : nums) {
            int ops = it / mid;
            if (it % mid == 0) {
                ops -= 1;
            }
            totalops += ops;
            if (totalops > maxi) {
                return false;
            }
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int result;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(nums, maxOperations, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};