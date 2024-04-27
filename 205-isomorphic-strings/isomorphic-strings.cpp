class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> sCharToTChar;
        unordered_map<char, char> tCharToSChar;

        for (int i = 0; i < s.size(); ++i) {
            if (sCharToTChar.find(s[i]) == sCharToTChar.end() &&
                tCharToSChar.find(t[i]) == tCharToSChar.end()) {
                sCharToTChar[s[i]] = t[i];
                tCharToSChar[t[i]] = s[i];
            } else {
                if (sCharToTChar[s[i]] != t[i] || tCharToSChar[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};