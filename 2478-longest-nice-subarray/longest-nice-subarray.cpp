class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 0; // maximum sized nice subarray
        int i = 0;    // left or sliding window
        int mask = 0; // storing the bitwise & values
        for (int j = 0; j < nums.size(); j++) {
            while ((mask & nums[j]) != 0) {
                // shrinking windows unless mask becomes 0 again
                mask ^= nums[i]; // removing the elemetn from window
                i++;             // shringked
            }
            mask |= nums[j];             // adding new value to mask using or
            maxi = max(maxi, j - i + 1); // storing the max size of nice
                                         // subarray
        }
        return maxi;
    }
};