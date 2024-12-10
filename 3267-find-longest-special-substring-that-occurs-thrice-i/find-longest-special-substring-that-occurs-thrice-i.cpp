class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mpp;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            for (int j = i; j < s.size() && s[j] == ch; j++) {
                string temp = s.substr(i, j - i + 1);
                mpp[temp]++;
            }
        }

        int maxlen = -1;

        for (auto it : mpp) {
            if (it.second >= 3) {
                maxlen = max(maxlen, (int)it.first.size());
            }
        }

        return maxlen;
    }
};