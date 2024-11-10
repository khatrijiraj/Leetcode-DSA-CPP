class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int currOR = 0;
        int mini = INT_MAX;

        int left = 0;
        vector<int> bits(32, 0);

        for (int right = 0; right < n; right++) {
            currOR |= nums[right];

            for (int bit = 0; bit < 32; bit++) {
                if (nums[right] & (1 << bit)) {
                    bits[bit]++;
                }
            }

            while (left <= right && currOR >= k) {
                mini = min(mini, right - left + 1);

                int newOR = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if (nums[left] & (1 << bit)) {
                        bits[bit]--;
                    }
                    if (bits[bit] > 0) {
                        newOR |= (1 << bit);
                    }
                }
                currOR = newOR;
                left++;
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};