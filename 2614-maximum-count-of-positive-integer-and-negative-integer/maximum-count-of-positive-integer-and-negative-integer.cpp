class Solution {
public:
    int maximumCount(vector<int>& nums) {
        /* int maxi = 0;
        int mini = 0;

        for (auto it : nums) {
            if (it < 0) {
                mini++;
            } else if (it == 0) {
                continue;
            } else {
                maxi++;
            }
        }

        return max(maxi, mini); */

        int siz = nums.size();

        int pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        return max(siz - pos, neg);
    }
};