class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> mpp;

        for (char ch : s) {
            mpp[ch]++;
        }

        for (char ch : t) {
            if (mpp[ch] == 0) {
                return false;
            }
            mpp[ch]--;
        }

        for (auto count : mpp) {
            if (count.second != 0) {
                return false;
            }
        }

        return true;
    }
};