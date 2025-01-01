class Solution {
public:
    int maxScore(string s) {
        /*

        Timecomplexity:  O(N^2) solution

        Simply splitting string in two parts and counting zeroinleft &
        oneinright then keeping a track of maximum score we seen in all possible
        splits:

        int maxi = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            int curr = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    curr++;
                }
            }
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == '1') {
                    curr++;
                }
            }
            maxi = max(maxi, curr);
        }
        return maxi;

        */

        /*

        OPTIMAL APPROACH ONE PASS SOLUTION:
        Timecomplexity: O(N) solution

        score = zeroinleft + oneinright

        but oneinright = totalones - oneinleft

        substituting this in equation 1:
        score = zeroinleft + totalone - oneinleft

        now we know totalone is constant so we just need to find a maximum
        value of:

        zeroinleft - oneinleft

        which only focuses on left part

        thus its a one pass solution

        */

        int zeros = 0;
        int ones = 0;

        int best = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }

            best = max(best, zeros - ones);
        }

        if (s[s.size() - 1] == '1') {
            ones++;
        }

        //score =  (zeroinleft - oneinleft) + totalone
        return best + ones;
    }
};