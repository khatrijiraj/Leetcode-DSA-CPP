class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        /* BRUTE APPAROCH
        TC- (N^3 * log(no. of unique triplets))

        set<vector<int>> stt;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (!sum) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        stt.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> result(stt.begin(), stt.end());
        return result;
        */

        /* BETTER APPROACH
        TC- O(N^2 * log(no. of unique triplets))
        USING HASHING
        set<vector<int>> stt;
        for (int i = 0; i < n; i++) {
            set<int> hashing;
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                if (hashing.find(third) != hashing.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    stt.insert(temp);
                }
                hashing.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(stt.begin(), stt.end());
        return ans;
         */

        /* OPTIMAL APPROACH - USING POINTERS
        TC - O(NlogN)+O(N^2)
        */
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return result;
    }
};