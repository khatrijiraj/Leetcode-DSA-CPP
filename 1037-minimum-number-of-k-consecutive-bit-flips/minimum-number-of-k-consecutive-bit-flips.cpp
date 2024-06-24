class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    // Brute Approach, TC:O(n*k) SC:O(1)
    //  int minKBitFlips(vector<int>& nums, int k) {
    //      int flips = 0;
    //      int size = nums.size();
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 0) {
    //             if (i + k - 1 >= size) {
    //                 return -1;
    //             }
    //             for (int j = i; j <= i + k - 1; j++) {
    //                 nums[j] = !nums[j];
    //             }
    //             flips++;
    //         }
    //     }
    //     return flips;
    // }

    // optimal approach TC: O(n) SC:O(n)
    int minKBitFlips(vector<int>& nums, int k) {
        std::queue<int> qu;
        int size = nums.size();
        int flips = 0;

        for (int i = 0; i < size; i++) {
            if (!qu.empty() && qu.front() < i) {
                qu.pop();
            }

            if (qu.size() % 2 == nums[i]) {
                if (i + k - 1 >= size) {
                    return -1;
                }
                qu.push(i + k - 1);
                flips++;
            }
        }
        return flips;
    }
};