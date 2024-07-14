class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push({});

        int i = 0;
        int size = formula.size();

        while (i < size) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                int start = ++i;
                while (i < size && isdigit(formula[i])) {
                    i++;
                }

                int multiplier =
                    (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                auto top = stk.top();
                stk.pop();

                for (auto& [atom, count] : top) {
                    stk.top()[atom] += count * multiplier;
                }
            } else {
                int start = i++;

                while (i < size && islower(formula[i])) {
                    i++;
                }

                string atom = formula.substr(start, i - start);

                start = i;
                while (i < size && isdigit(formula[i])) {
                    i++;
                }

                int count =
                    (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                stk.top()[atom] += count;
            }
        }

        map<string, int> mpp;

        for (auto& [atom, count] : stk.top()) {
            mpp[atom] += count;
        }

        string result;
        for (auto& [atom, count] : mpp) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};