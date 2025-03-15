class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mini = 1;
        int maxi = *max_element(nums.begin(), nums.end());
        int total = nums.size();

        while (mini < maxi) {
            int mid = mini + (maxi - mini) / 2;
            int thefts = 0;

            for (int i = 0; i < total; i++) {
                if (nums[i] <= mid) {
                    thefts += 1;
                    i++;
                }
            }

            if (thefts >= k) {
                maxi = mid;
            } else {
                mini = mid + 1;
            }
        }

        return mini;
    }
};