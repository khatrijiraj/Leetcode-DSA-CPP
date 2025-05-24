class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            for (auto it : words[i]) {
                if (it == x) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};