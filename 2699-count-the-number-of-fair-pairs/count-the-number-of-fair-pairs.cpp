class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        /*
        BASIC APPROACH TLE
        long long count  = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int sum = nums[i] + nums[j];
                if(lower <= sum && sum <= upper){
                    count++;
                }
            }
        }

        return count; */

        long long count = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // first i < j nums[i] + nums[j] >= lower
            int lbound =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin();
            // first i < j nums[i] + nums[j] > upper
            int ubound =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin();

            count += (ubound - lbound);
        }

        return count;
    }
};
