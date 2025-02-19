class Solution {
    void solve(string& current, int n, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!current.empty() && current.back() == ch) {
                continue;
            }

            current.push_back(ch);     // DO
            solve(current, n, result); // EXPLORE
            current.pop_back();        // UNDO
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string> result;
        string current = "";

        solve(current, n, result);

        if (k > result.size()) {
            return "";
        }

        return result[k - 1];
    }
};