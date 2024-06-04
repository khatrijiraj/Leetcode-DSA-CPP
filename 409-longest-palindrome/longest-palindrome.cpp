class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        for (auto& ch : s) {
            mpp[ch]++;
        }

        int length = 0;
        bool oddfound = false;
        for (auto& ch : mpp) {
            if (ch.second % 2 == 0) {
                length += ch.second;
            } else {
                length += ch.second - 1;
                oddfound = true;
            }
        }

        if (oddfound) {
            length++;
        }

        return length;
    }
};