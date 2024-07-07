class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int candy(vector<int>& ratings) {
        // TC: O(3N) SC:O(N);
        // int n = ratings.size();

        // vector<int> candies(n, 1);

        // for (int i = 1; i < n; i++) {
        //     if (ratings[i] > ratings[i - 1]) {
        //         candies[i] = candies[i - 1] + 1;
        //     }
        // }

        // for (int i = n - 2; i >= 0; i--) {
        //     if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
        //     {
        //         candies[i] = candies[i + 1] + 1;
        //     }
        // }

        // int total = 0;
        // for (int it : candies) {
        //     total += it;
        // }

        // return total;

        // TC: O(N) SC:O(1);
        int n = ratings.size();

        if (n == 0) {
            return 0;
        }

        int total = 1;
        int peak = 0;
        int up = 0;
        int down = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                total += up + 1;
            } else if (ratings[i] < ratings[i - 1]) {
                up = 0;
                down++;
                total += down;
                if (down > peak) {
                    total++;
                }
            } else {
                peak = up = down = 0;
                total++;
            }
        }

        return total;
    }
};