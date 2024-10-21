class Solution {
private:
    int solve(string& s, int i, unordered_set<string>& stt) {
        if (i == s.size()) {
            return stt.size();
        }

        int maxi = 0;
        for (int j = i; j < s.size(); j++) {
            string str = s.substr(i, j - i + 1);
            if (stt.find(str) == stt.end()) {
                stt.insert(str);
                maxi = max(maxi, solve(s, j + 1, stt));
                stt.erase(str);
            }
        }

        return maxi;
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> stt;
        return solve(s, 0, stt);
    }
};