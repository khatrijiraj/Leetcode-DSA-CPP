class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        /* BETTER APPAROCH
        USING HASHING
        TC:- O(N*logN)
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mpp;
        int mini = int(n / 3) + 1;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            if (mpp[nums[i]] == mini) {
                result.push_back(nums[i]);
            }
            if (result.size() == 2) {
                break;
            }
        }
        return result;
         */

        /* OPTIMAL APPRAOCH
        Extended Boyer Moore’s Voting Algorithm

        TC:- O(N) + O(N)
        */
        int count1 = 0;
        int count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != element2) {
                element1 = nums[i];
                count1++;
            } else if (count2 == 0 && nums[i] != element1) {
                element2 = nums[i];
                count2++;
            } else if (nums[i] == element1) {
                count1++;
            } else if (nums[i] == element2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (auto it : nums) {
            if (it == element1) {
                count1++;
            }
            if (it == element2) {
                count2++;
            }
        }

        vector<int> result;
        if (count1 > nums.size() / 3) {
            result.push_back(element1);
        }
        if (count2 > nums.size() / 3) {
            result.push_back(element2);
        }
        return result;
    }
};