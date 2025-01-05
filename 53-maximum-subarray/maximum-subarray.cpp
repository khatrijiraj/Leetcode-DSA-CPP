class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        /*
        BRUTE
        TC:- O(N^3)

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return maxi;
         */

        /* BETTER APPROACH
        TC:- O(N^2)

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
         */

        /* OPTIMAL APPROACH
        KADANE ALGO:- it focuses on carying postive sum forward and neglecting
        -ve sum TC:- O(N)

        */
        int maxi = nums[0];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(sum, maxi);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};