#include<stack>
#include<string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        stack<int> stack;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();
                int result = applyOperator(token, operand1, operand2);
                stack.push(result);
            } else {
                stack.push(stoi(token));
            }
        }

        return stack.top();
    }

private:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int applyOperator(const std::string& op, int operand1, int operand2) {
        if (op == "+")
            return operand1 + operand2;
        if (op == "-")
            return operand1 - operand2;
        if (op == "*")
            return operand1 * operand2;
        if (op == "/")
            return operand1 / operand2;
        throw invalid_argument("Invalid operator");
    }
};