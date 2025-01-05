class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        /* BRUTE:
        TC -  O(N+N/2)
        vector<int> pos;
        vector<int> neg;

        for (auto it : nums) {
            if (it < 0) {
                neg.push_back(it);
            } else {
                pos.push_back(it);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }
        return nums;
        */

        /* OPTIMAL APPROACH
        one Pass solution
        TC - O(N)
        */
        vector<int> result(n);
        int pos = 0, neg = 1;
        for (auto it : nums) {
            if (it < 0) {
                result[neg] = it;
                neg += 2;
            } else {
                result[pos] = it;
                pos += 2;
            }
        }
        return result;
    }
};