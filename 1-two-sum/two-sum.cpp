class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* brute approach
                       for (int i = 0; i < nums.size(); i++) {
                           for (int j = i + 1; j < nums.size(); j++) {
                               if ((nums[i] + nums[j]) == target) {
                                   return {i, j};
                               }
                           }
                       }
                       return {-1, -1}; */

        /*
        better approach
         */
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int req = target - nums[i];
            if (mpp.find(req) != mpp.end()) {
                return {mpp[req], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};

        /* best solution

         */
    }
};