class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> converted;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int sum = 0;
            int place = 1;

            if (temp == 0) {
                sum = mapping[0];
            }
            
            while (temp) {
                int last = temp % 10;
                sum += place * (mapping[last]);
                temp /= 10;
                place *= 10;
            }
            converted.push_back({sum, i});
        }

        sort(converted.begin(), converted.end());

        vector<int> result;
        for (auto& it : converted) {
            result.push_back(nums[it.second]);
        }

        return result;
    }
};