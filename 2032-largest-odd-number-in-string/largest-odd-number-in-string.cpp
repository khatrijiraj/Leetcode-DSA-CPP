class Solution {
public:
    string largestOddNumber(string num) {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};