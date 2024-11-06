class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        bool swapped = true;
        while (swapped) {
            swapped = false;
            for (int i = 0; i < nums.size() - 1; i++) {
                if ((nums[i] > nums[i + 1]) &&
                    (__builtin_popcount(nums[i]) ==
                     __builtin_popcount(nums[i + 1]))) {
                    swap(nums[i], nums[i + 1]);
                    swapped = true;
                } else if ((nums[i] > nums[i + 1]) &&
                           (__builtin_popcount(nums[i]) !=
                            __builtin_popcount(nums[i + 1]))) {
                    return false;
                }
            }
        }
        return true;
    }
};
