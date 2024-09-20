class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }

        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "-" + rev;

        int size = combined.size();
        vector<int> LPS(size, 0);

        for (int i = 1; i < size; i++) {
            int j = LPS[i - 1];

            while (j > 0 && combined[i] != combined[j]) {
                j = LPS[j - 1];
            }

            if (combined[i] == combined[j]) {
                j++;
            }

            LPS[i] = j;
        }

        int palinlen = LPS[size - 1];

        string add = s.substr(palinlen);

        reverse(add.begin(), add.end());

        return add + s;
    }
};