class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size2 = nums2.size();

        unordered_map<int, int> mpp;
        vector<int> result;
        stack<int> stk;

        for (int i = size2 - 1; i >= 0; i--) {
            int curr = nums2[i];

            while (!stk.empty() && stk.top() <= curr) {
                stk.pop();
            }

            if (stk.empty()) {
                mpp[curr] = -1;
            } else {
                mpp[curr] = stk.top();
            }

            stk.push(curr);
        }

        for (auto it : nums1) {
            result.push_back(mpp[it]);
        }

        return result;
    }
};