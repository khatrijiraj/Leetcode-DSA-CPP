class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalsum = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftsum = 0;
        
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftsum += nums[i];
            if (leftsum >= (totalsum - leftsum)) {
                count++;
            }
        }

        return count;
    }
};