class Solution {
private:
    char solve(vector<char>& temp, char& op) {
        if (op == '!') {
            if (temp[0] == 't') {
                return 'f';
            } else {
                return 't';
            }
        }

        if (op == '&') {
            for (auto& it : temp) {
                if (it == 'f') {
                    return 'f';
                }
            }
            return 't';
        }

        if (op == '|') {
            for (auto& it : temp) {
                if (it == 't') {
                    return 't';
                }
            }
            return 'f';
        }

        return 't';
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (auto& it : expression) {
            if (it == ',') {
                continue;
            }

            if (it == ')') {
                vector<char> temp;
                while (stk.top() != '(') {
                    temp.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();

                char op = stk.top();
                stk.pop();

                char result = solve(temp, op);

                stk.push(result);
            } else {
                stk.push(it);
            }
        }

        return stk.top() == 't';
    }
};