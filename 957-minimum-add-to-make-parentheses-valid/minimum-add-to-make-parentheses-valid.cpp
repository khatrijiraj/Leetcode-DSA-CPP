class Solution {
public:
    int minAddToMakeValid(string s) {
        int close = 0;
        stack<char> stk;

        for (auto it : s) {
            if (it == ')') {
                if (stk.empty()) {
                    close++;
                } else {
                    stk.pop();
                }
            } else {
                stk.push(it);
            }
        }

        return close + stk.size();
    }
};