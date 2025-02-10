class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        string result = "";
        for (auto it : s) {
            if (isdigit(it) == false) {
                stk.push(it);
            } else {
                stk.pop();
            }
        }
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};