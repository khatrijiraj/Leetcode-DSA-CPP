class Solution {
private:
    void addwordstomap(unordered_map<string, int>& mpp, string str) {
        stringstream ss(str);
        string temp;
        while (ss >> temp) {
            mpp[temp]++;
        }
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        vector<string> result;
        addwordstomap(mpp, s1);
        addwordstomap(mpp, s2);

        for (auto& it : mpp) {
            if (it.second == 1) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};