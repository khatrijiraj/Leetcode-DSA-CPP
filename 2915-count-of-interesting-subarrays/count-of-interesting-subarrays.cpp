class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> mpp;
        int prefix = 0;
        long long result = 0;
        
        mpp[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i] % modulo == k;
            result += mpp[(prefix - k + modulo) % modulo];
            mpp[prefix % modulo]++;
        }
        
        return result;
    }
};