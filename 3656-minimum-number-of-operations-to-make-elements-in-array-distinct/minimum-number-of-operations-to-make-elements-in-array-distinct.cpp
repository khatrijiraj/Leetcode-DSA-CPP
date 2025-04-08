class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,bool> mpp;
        for(int i = nums.size() - 1; i >=0; i--){
            if(mpp[nums[i]]){
                return i / 3 + 1;
            }
            mpp[nums[i]] = true;
        }
        return 0;
    }
};