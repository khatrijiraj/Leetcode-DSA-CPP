class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /* doubling the nums array hypothetical
        and then applying monotonic logic

        TC- O(4N)
        SC - O(2N)
        */
        stack<int> stk;
        int n = nums.size();

        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];
            while (!stk.empty() && stk.top() <= curr) {
                stk.pop();
            }

            if (i < n) {
                if (stk.empty()) {
                    nums[i % n] = -1;
                } else {
                    nums[i % n] = stk.top();
                }
            }
            stk.push(curr);
        }
        return nums;
    }
};