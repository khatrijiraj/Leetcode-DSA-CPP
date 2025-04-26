class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        /* BRUTE APPROACH
        long long count = 0;
        int n = nums.size();
        for (int left = 0; left < n; left++) {
            int mini = nums[left];
            int maxi = nums[left];
            for (int right = left; right < n; right++) {
                mini = min(mini, nums[right]);
                maxi = max(maxi, nums[right]);
                if (mini == minK && maxi == maxK) {
                    count++;
                }
            }
        }
        return count;
         */

        int mini = -1, maxi = -1;
        int leftBound = -1;

        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i;
            }
            
            if (nums[i] == minK) {
                mini = i;
            }
            
            if (nums[i] == maxK) {
                maxi = i;
            }
            
            int count = min(maxi, mini) - leftBound;
            
            if (count <= 0) {
                result += 0;
            } else {
                result += count;
            }
        }

        return result;
    }
};