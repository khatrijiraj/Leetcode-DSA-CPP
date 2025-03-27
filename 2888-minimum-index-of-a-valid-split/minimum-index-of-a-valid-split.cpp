class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int majorityele = nums[0];
        int count = 0;
        int majcount = 0;
        int n = nums.size();

        for (auto& it : nums) {
            if (it == majorityele) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                majorityele = it;
                count = 1;
            }
        }

        for (auto& it : nums) {
            if (it == majorityele) {
                majcount++;
            }
        }

        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majorityele) {
                count++;
            }
            int remain = majcount - count;
            if (count * 2 > i + 1 && remain * 2 > n - i - 1) {
                return i;
            }
        }
        return -1;
    }
};