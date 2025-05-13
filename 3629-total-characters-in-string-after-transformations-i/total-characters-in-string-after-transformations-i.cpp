class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        
        vector<int> mpp(26);
        
        for (auto it : s) {
            mpp[it - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            int ele = mpp[25];
            for (int j = 25; j > 0; j--) {
                mpp[j] = mpp[j - 1];
            }
            mpp[0] = 0;
            mpp[0] = (mpp[0] + ele) % MOD;
            mpp[1] = (mpp[1] + ele) % MOD;
        }
        
        int sum = 0;
        
        for (int i = 0; i < 26; i++) {
            sum = (sum + mpp[i]) % MOD;
        }
        
        return sum;
    }
};