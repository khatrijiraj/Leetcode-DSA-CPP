class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        /*
        BRUTE APPROACH:

        TC:- O(M * N);

        Based on simulating the problem

        for (auto it : shifts) {
            int dir = it[2];
            for (int i = it[0]; i <= it[1]; i++) {
                char ch = s[i];

                if (ch == 'z' && dir == 1) {
                    ch = 'a';
                } else if (ch == 'a' && dir == 0) {
                    ch = 'z';
                } else {
                    if (dir) {
                        ch++;
                    } else {
                        ch--;
                    }
                }

                s[i] = ch;
            }
        }

        return s;
        */

        /*
        OPTIMAL APPROACH
        newChar= 'a'+(oldChar−'a'+numberOfShifts) mod 26

        TC :- O(M + N)
         */

        int n = s.length();
        vector<int> diff(n, 0);

        for (auto it : shifts) {
            int start = it[0];
            int end = it[1] + 1;
            int dir = it[2];

            if (dir) {
                diff[start]++;
                if (end < n) {
                    diff[end]--;
                }
            } else {
                diff[start]--;
                if (end < n) {
                    diff[end]++;
                }
            }
        }

        int currshift = 0;
        for (int i = 0; i < n; i++) {
            currshift += diff[i];

            // finding newchar modding with 26 to round from a to z
            int newch = (s[i] - 'a' + currshift) % 26;

            if (newch < 0) {
                newch += 26;
            }

            s[i] = 'a' + newch;
        }

        return s;
    }
};