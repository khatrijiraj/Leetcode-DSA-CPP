class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int total = 1 << size;
        vector<vector<int>> result;

        for(int mask = 0; mask < total; mask++){
            vector<int> temp;
            for(int j = 0; j < size; j++){
                if(mask & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};