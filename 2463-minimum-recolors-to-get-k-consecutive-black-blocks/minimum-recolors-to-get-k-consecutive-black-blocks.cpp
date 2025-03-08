class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
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

        return mini;
    }
};