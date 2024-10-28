class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_set<long> stt;

        for (auto it : nums) {
            stt.insert(it);
        }

        int maxi = 0;

        for (auto it : nums) {
            long current = it;
            int streak = 1;

            while (stt.find(current * current) != stt.end()) {
                current *= current;
                streak++;
            }

            if (streak >= 2) {
                maxi = max(maxi, streak);
            }
        }

        return maxi >= 2 ? maxi : -1;
    }
};