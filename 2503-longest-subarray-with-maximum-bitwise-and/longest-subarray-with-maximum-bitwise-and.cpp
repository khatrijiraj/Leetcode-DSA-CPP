class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int streak = 0;
        int longest = 0;
        for (auto& it : nums) {
            if (it > maxi) {
                maxi = it;
                streak = 1;
                longest = 1;
            } else if (it == maxi) {
                streak++;
                longest = max(longest, streak);
            } else {
                streak = 0;
            }
        }
        return longest;
    }
};