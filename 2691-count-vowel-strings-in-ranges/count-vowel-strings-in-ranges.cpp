class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> prefixsum(n);

        unordered_set<char> stt;
        stt.insert('a');
        stt.insert('e');
        stt.insert('i');
        stt.insert('o');
        stt.insert('u');

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (stt.find(words[i][0]) != stt.end() &&
                stt.find(words[i][words[i].size() - 1]) != stt.end()) {
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