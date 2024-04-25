class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int opened = 0;
        for (char ch : s) {
            if (ch == '(' && opened++ > 0) {
                ans += ch;
            }
            if (ch == ')' && opened-- > 1) {
                ans += ch;
            }
        }
        return ans;
    }
};