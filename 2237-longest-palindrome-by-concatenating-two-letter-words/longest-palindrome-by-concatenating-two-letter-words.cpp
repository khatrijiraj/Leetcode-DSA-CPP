class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        int result = 0;
        for (auto it : words) {
            string rev = it;
            reverse(rev.begin(), rev.end());
            if (mpp[rev] > 0) {
                result += 4;
                mpp[rev]--;
            } else {
                mpp[it]++;
            }
        }

        for (auto it : mpp) {
            if (it.first[0] == it.first[1] && it.second > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};