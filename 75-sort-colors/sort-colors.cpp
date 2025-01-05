class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        brute approach
        tc - N(logN)
        sort(nums.begin(), nums.end());
         */

        /*
        better approach
        keeping count of elements
        TC = 2 * O(N)

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for (auto it : nums) {
            if (it == 0)
                count0++;
            if (it == 1)
                count1++;
            if (it == 2)
                count2++;
        }

        for (int i = 0; i < count0; i++) {
            nums[i] = 0;
        }
        for (int i = count0; i < count0 + count1; i++) {
            nums[i] = 1;
        }
        for (int i = count0 + count1; i < count1 + count2 + count0; i++) {
            nums[i] = 2;
        }
         */

        /*
        OPTIMAL APPROACH - DUTCH nATIONAL FLAG ALGO
        TC - O(N)
         */

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};