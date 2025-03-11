class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;

        int i = 0;
        int j = 0;

        int size = s.length();

        vector<int> mpp(3, 0);

        while (j < size) {
            char ch = s[j];
            mpp[ch - 'a']++;
            while (mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0) {
                result += size - j;
                mpp[s[i] - 'a']--;
                i++;
            }
            j++;
        }

        return result;
    }
};