class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int minSwaps(vector<int>& nums) {
        int maxones = 0;
        for (auto& it : nums) {
            if (it == 1) {
                maxones++;
            }
        }

        if (!maxones) {
            return 0;
        }

        int currentones = 0;
        int ones = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();

        while (r < 2 * n) {
            if (r - l < maxones) {
                if (nums[r % n] == 1) {
                    ones++;
                }
                r++;
            } else {
                currentones = max(currentones, ones);
                if (nums[l % n] == 1) {
                    ones--;
                }
                l++;
            }
        }

        int swaps = maxones - currentones;
        return swaps;
    }
};