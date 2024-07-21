class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> mpp;
        for (auto ch : licensePlate) {
            if (isalpha(ch)) {
                mpp[tolower(ch)]++;
            }
        }

        string result;
        int mini = INT_MAX;

        for (auto word : words) {
            if (word.length() >= mini) {
                continue;
            }
            
            unordered_map<char, int> temp;
            for (char ch : word) {
                temp[ch]++;
            }

            bool valid = true;
            for (auto [key, value] : mpp) {
                if (temp[key] < value) {
                    valid = false;
                    break;
                }
            }

            if (valid && word.length() < mini) {
                result = word;
                mini = word.length();
            }
        }

        return result;
    }
};