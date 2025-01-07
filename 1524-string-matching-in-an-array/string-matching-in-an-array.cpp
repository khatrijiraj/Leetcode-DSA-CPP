class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        /* BRUTE APPROACH
        TC:- O(N^2 * M)
         */
        int n = words.size();
        vector<string> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } else {
                    if (words[j].find(words[i]) != string::npos) {
                        result.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return result;
    }
};