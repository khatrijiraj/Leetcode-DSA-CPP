class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffarray(n, 0);
        for (auto it : queries) {
            int x = it[0];
            int y = it[1];

            diffarray[x] += 1;
            if (y + 1 < n) {
                diffarray[y + 1] -= 1;
            }
        }
        int sum = 0;
        vector<int> result;
        vector<int> cummsum;
        for (auto it : diffarray) {
            cummsum.push_back(sum += it);
        }

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int cum = cummsum[i];
            if (val > cum) {
                return false;
            }
        }

        return true;
    }
};