class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && k > 0 &&
                   ((stk.top() - '0') > (num[i] - '0'))) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        string res = "";

        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        while (res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};