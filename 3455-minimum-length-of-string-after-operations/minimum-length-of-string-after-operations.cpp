class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> mpp(26, 0);

        for (char it : s) {
            mpp[it - 'a']++;
        }

        int res = 0;

        for (int it : mpp) {
            if (it == 0) {
                continue;
            }

            if (it % 2 == 0) {
                res += 2;
            } else {
                res += 1;
            }
        }

        return res;
    }
};