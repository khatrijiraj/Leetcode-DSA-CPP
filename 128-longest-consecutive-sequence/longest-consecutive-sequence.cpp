class Solution {
    /* bool linearSearch(int n, vector<int>& nums) {
        for (auto it : nums) {
            if (it == n) {
                return true;
            }
        }
        return false;
    } */

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        /* BRUTE:
            TC:-  O(N ^ 2)
            for each element iterating for consecutive

        int maxi = 1;
        for (auto it : nums) {
            int count = 1;
            while (linearSearch(++it, nums)) {
                count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
         */

        /* BETTER Approach: sorting + iterating
        TC:- O(NlogN) + O(N)
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                maxi = max(maxi, count);
                count = 1;
            }
        }
        return max(maxi, count);
         */

        /* OPTIMAL APPROACH
        TC:-  O(N) + O(2*N) ~ O(3*N)
       */
        unordered_set<int> stt;
        for (auto it : nums) {
            stt.insert(it);
        }

        int maxi = 1;
        for (auto it : stt) {
            if (stt.find(it - 1) == stt.end()) {
                int count = 1;
                while (stt.find(++it) != stt.end()) {
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};