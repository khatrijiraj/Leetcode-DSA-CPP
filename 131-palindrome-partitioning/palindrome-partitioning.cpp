class Solution {
private:
    void helper(string s, int index, vector<string>& temp,
                vector<vector<string>>& result) {
        if (index == s.length()) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (ispalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                helper(s, i + 1, temp, result);
                temp.pop_back();
            }
        }
    }

    bool ispalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        helper(s, 0, temp, result);
        return result;
    }
};