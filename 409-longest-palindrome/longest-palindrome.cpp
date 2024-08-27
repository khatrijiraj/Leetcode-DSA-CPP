class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        for (auto& it : s) {
            mpp[it]++;
        }

        int length = 0;
        bool odd = false;
        for (auto& it : mpp) {
            if (it.second % 2 == 0) {
                length += it.second;
            } else {
                length += it.second - 1;
                odd = true;
            }
        }
        if (odd) {
            length++;
        }

        return length;
    }
};