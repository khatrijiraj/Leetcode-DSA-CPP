class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int longestSubarray(vector<int>& nums, int limit) {
        std::deque<int> minDeque, maxDeque;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!minDeque.empty() && minDeque.back() > nums[right]) {
                minDeque.pop_back();
            }
            while (!maxDeque.empty() && maxDeque.back() < nums[right]) {
                maxDeque.pop_back();
            }

            minDeque.push_back(nums[right]);
            maxDeque.push_back(nums[right]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[left] == minDeque.front()) {
                    minDeque.pop_front();
                }
                if (nums[left] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                ++left;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};