class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> countBits(int n) {
        vector<int> result;

        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int num = i;
            while (num) {
                count += num & 1;
                num >>= 1;
            }
            result.push_back(count);
        }

        return result;
    }
};