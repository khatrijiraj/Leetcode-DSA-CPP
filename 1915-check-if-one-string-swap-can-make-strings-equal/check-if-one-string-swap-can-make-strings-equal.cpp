class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        /*
        two mismatched indices i & j
        so if these two condition will satisfy then in one swap it is possible
        else not possible
        s1[i] == s2[j]
        s1[j] == s2[i]
         */

        // storing the indices
        int i = 0;
        int j = 0;

        // if diff in indices for two string is more than 2 it is not possible
        // to make them equal with just one swap as per question
        int diff = 0;

        for (int x = 0; x < s1.size(); x++) {
            if (s1[x] != s2[x]) {
                diff++;

                if (diff > 2) {
                    // diff > 2 hence not possible as stated above
                    return false;
                } else if (diff == 1) {
                    // storing first index of diff
                    i = x;
                } else {
                    // storing second index of diff
                    j = x;
                }
            }
        }

        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};