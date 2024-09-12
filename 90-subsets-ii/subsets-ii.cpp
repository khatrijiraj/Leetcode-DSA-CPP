class Solution {
private:
    void helper(int index, vector<int>& nums, vector<int>&temp, vector<vector<int>>& result){
        result.push_back(temp);
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            helper(i + 1, nums, temp, result);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(0,nums, temp, result);
        return result;
    }
};