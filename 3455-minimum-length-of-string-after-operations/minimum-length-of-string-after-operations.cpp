class Solution {
public:
    int minimumLength(string s) {
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