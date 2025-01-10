class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> mppuniversal;

        for (auto w2 : words2) {
            unordered_map<char, int> w2chfreq;
            for (char ch : w2) {
                w2chfreq[ch]++;
            }
            for (auto f2 : w2chfreq) {
                mppuniversal[f2.first] = max(mppuniversal[f2.first], f2.second);
            }
        }

        vector<string> result;
        for (auto w1 : words1) {
            unordered_map<char, int> w1chfreq;
            for (char ch : w1) {
                w1chfreq[ch]++;
            }

            bool isValid = true;
            for (auto unifreq : mppuniversal) {
                if (w1chfreq[unifreq.first] < unifreq.second) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(w1);
            }
        }

        return result;
    }
};
