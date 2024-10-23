class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return {};
        }
        
        unordered_map<string, int> mpp;
        for (int i = 0; i <= s.size() - 10; i++) { 
            mpp[s.substr(i, 10)]++;  
        }

        vector<string> result;
        for (const auto& it : mpp) {
            if (it.second > 1) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};
