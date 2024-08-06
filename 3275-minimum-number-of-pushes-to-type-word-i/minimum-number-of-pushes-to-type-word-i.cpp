class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (auto& it : word) {
            freq[it - 'a']++;
        }

        sort(freq.begin(), freq.end(), [](int& a, int& b) { return a > b; });

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += freq[i] * (i / 8 + 1);
        }

        return result;
    }
};