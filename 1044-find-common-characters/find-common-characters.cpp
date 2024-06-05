class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        vector<int> mini(26, INT_MAX);

        for (const string& word : words) {
            vector<int> charcount(26, 0);
            for (const char& ch : word) {
                charcount[ch - 'a']++;
            }
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                mini[ch - 'a'] = min(mini[ch - 'a'], charcount[ch - 'a']);
            }
        }

        vector<string> result;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (mini[ch - 'a'] == 0) {
                continue;
            }
            for (int i = 0; i < mini[ch - 'a']; ++i) {
                result.push_back(string(1, ch));
            }
        }

        return result;
    }
};