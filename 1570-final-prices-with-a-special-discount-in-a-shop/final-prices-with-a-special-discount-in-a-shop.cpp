class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size(); i++) {
            int discount = INT_MAX;
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    discount = min(discount, prices[j]);
                    break;
                }
            }
            if (discount != INT_MAX) {
                prices[i] -= discount;
            }
        }
        return prices;
    }
};