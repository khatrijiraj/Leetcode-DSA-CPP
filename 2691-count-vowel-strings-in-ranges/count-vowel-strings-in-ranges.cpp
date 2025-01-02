class Solution {
private:
    bool isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> prefixsum(n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (isvowel(words[i].front()) && isvowel(words[i].back())) {
                sum++;
            }
            prefixsum[i] = sum;
        }

        vector<int> result;
        for (auto it : queries) {
            int left = 0;
            int right = prefixsum[it[1]];
            if (it[0] > 0) {
                left = prefixsum[it[0] - 1];
            }
            result.push_back(right - left);
        }

        return result;
    }
};