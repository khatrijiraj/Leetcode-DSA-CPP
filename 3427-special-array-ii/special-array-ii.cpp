class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        /*
        BRUTEE TLE

                       vector<bool> paritycheck(nums.size() - 1, false);

                        for (int i = 0; i < nums.size() - 1; i++) {
                            paritycheck[i] = nums[i] % 2 == nums[i + 1] % 2;
                        }

                        vector<bool> result;

                        for (auto it : queries) {
                            int start = it[0];
                            int end = it[1];

                            bool isspecial = true;

                            for (int i = start; i < end; i++) {
                                if (paritycheck[i]) {
                                    isspecial = false;
                                    break;
                                }
                            }

                            result.push_back(isspecial);
                        }

                        return result;
        */

        int n = nums.size();

        vector<int> prefix(n, 0);

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 != nums[i + 1] % 2) {
                prefix[i + 1] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        vector<bool> result;

        for (auto it : queries) {
            int start = it[0];
            int end = it[1];

            int mismatch = prefix[end] - prefix[start];

            if (mismatch == (end - start)) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};