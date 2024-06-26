class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> seen;

        for(int i = 0; i < nums.size(); i++){
            if(seen.find(nums[i]) != seen.end()){
                int last = seen[nums[i]];
                if(i - last <= k){
                    return true;
                }
            }
            seen[nums[i]] = i;
        }

        return false;
    }
};