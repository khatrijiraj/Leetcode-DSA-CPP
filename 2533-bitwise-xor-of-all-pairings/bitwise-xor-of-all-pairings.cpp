class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int xori = 0;

        if (m % 2 != 0) {
            for (auto it : nums2) {
                xori ^= it;
            }
        }

        if (n % 2 != 0) {
            for (auto it : nums1) {
                xori ^= it;
            }
        }

        return xori;
    }
};