class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /* BRUTE APPROACH
            TC:- O(N^2)
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] > prices[i]) {
                    maxi = max(maxi, prices[j] - prices[i]);
                }
            }
        }
        return maxi;
        */

        /* OPTIMAL APPROACH
            TC:- O(N)
         */
        int maxi = 0;
        int mini = prices[0];
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};