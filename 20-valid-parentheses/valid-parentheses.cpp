class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char it : s) {
            if (it == '{' || it == '[' || it == '(') {
                stk.push(it);
            }
            if (stk.empty()) {
                return false;
            }
            if (it == '}') {
                if (stk.top() != '{') {
                    return false;
                }
                stk.pop();
            }
            if (it == ']') {
                if (stk.top() != '[') {
                    return false;
                }
                stk.pop();
            }
            if (it == ')') {
                if (stk.top() != '(') {
                    return false;
                }
                stk.pop();
            }
        }

        if (stk.empty()) {
            return true;
        }

        return false;
    }
};