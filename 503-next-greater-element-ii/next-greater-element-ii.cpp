class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int n = nums.size();
        vector<int> nextgreater(n, -1);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i % n]) {
                stk.pop();
            }

            if (i < n) {
                if (!stk.empty()) {
                    nextgreater[i] = stk.top();
                }
            }
            stk.push(nums[i % n]);
        }
        return nextgreater;
    }
};