class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    string sortSentence(string s) {
        map<int, string> mpp;
        int index = 0;
        string temp = "";
        while (index <= s.size()) {
            if (s[index] == '\0' || s[index] == ' ') {
                int last = temp.back();
                temp.pop_back();
                mpp[last] = temp;
                temp = "";
            } else {
                temp += s[index];
            }
            index++;
        }
        // int last = temp.back();
        // temp.pop_back();
        // mpp[last] = temp;

        string result = "";

        for (auto it : mpp) {
            result += it.second + " ";
        }
        result.pop_back();
        return result;
    }
};