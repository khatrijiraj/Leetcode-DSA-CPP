class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int reqrolls = rolls.size() + n;
        int reqsum = mean * reqrolls;

        int currsum = 0;
        for (auto it : rolls) {
            currsum += it;
        }

        int diff = reqsum - currsum;

        if (diff > n * 6 || diff < n) {
            return {};
        }

        vector<int> result(n, 1);

        int remainingdiff = diff - n;

        for (int i = 0; i < n && remainingdiff > 0; i++) {
            int add = min(remainingdiff, 5);
            result[i] += add;
            remainingdiff -= add;
        }

        return result;
    }
};