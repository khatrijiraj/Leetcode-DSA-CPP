class Solution {
private:
    int solve(int i, int xori, vector<int>& nums){
        if(i == nums.size()){
            return xori;
        }

        int take = solve(i+1, xori ^ nums[i], nums);
        int nottake = solve(i+1, xori, nums);

        return take + nottake;
    }

public:
    int subsetXORSum(vector<int>& nums) {
       return solve(0, 0, nums);
    }
};