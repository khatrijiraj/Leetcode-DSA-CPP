class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 1;
            int last = 0;
            for (int num : nums) {
                if (last + num > mid) {
                    count++;
                    last = num;
                } else {
                    last += num;
                }
            }
            if (count > k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};