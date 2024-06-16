class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        long long reach = 0;
        int i = 0;

        while (reach < n) {
            if (i < nums.size() && nums[i] <= reach + 1) {
                reach += nums[i];
                i++;
            } else {
                int ele = reach + 1;
                reach += ele;
                patch += 1;
            }
        }
        return patch;
    }
};