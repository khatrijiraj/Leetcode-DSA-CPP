class Solution {
private:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int mid) {
        int n = nums.size();
        vector<int> diff(n + 1);

        for (int q = 0; q < mid; q++) {
            int start = queries[q][0];
            int end = queries[q][1];
            int val = queries[q][2];

            diff[start] += val;
            diff[end + 1] -= val;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size();

        if (!check(nums, queries, right)) {
            return -1;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, queries, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};