class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0;
        vector<string> result;

        for (int right = 1; right <= nums.size(); right++) {
            if (right == nums.size() || nums[right] != nums[right - 1] + 1) {
                if (left == right - 1) {
                    result.push_back(to_string(nums[left]));
                } else {
                    result.push_back(to_string(nums[left]) + "->" +
                                     to_string(nums[right - 1]));
                }
                left = right;
            }
        }

        return result;
    }
};