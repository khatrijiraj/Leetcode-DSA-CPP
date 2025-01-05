class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long long> diff(n, 0);

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = i + 1;

            diff[start] += shifts[i];

            if (end < n) {
                diff[end] -= shifts[i];
            }
        }

        long long currsum = 0;
        for (int i = 0; i < s.length(); i++) {
            currsum += diff[i];

            int currch = s[i] - 'a';
            int newch = (currch + currsum) % 26;

            if (newch < 0) {
                newch += 26;
            }

            s[i] = 'a' + newch;
        }

        return s;
    }
};