class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // O(N * K) solution
        /* int left = 0;
        int right = k - 1;

        int mini = INT_MAX;
        while (right < blocks.length()) {
            int whites = 0;
            for (int i = left; i <= right; i++) {
                if (blocks[i] == 'W') {
                    whites++;
                }
            }
            mini = min(mini, whites);
            left++;
            right++;
        }

        return mini; */

        // O(N) solution
        int left = 0;
        int right = 0;
        int whites = 0;
        int mini = INT_MAX;

        while (right < blocks.size()) {
            if (blocks[right] == 'W') {
                whites++;
            }

            if (right - left + 1 == k) {
                mini = min(mini, whites);

                if (blocks[left] == 'W') {
                    whites--;
                }

                left++;
            }

            right++;
        }

        return mini;
    }
};