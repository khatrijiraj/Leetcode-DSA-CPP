class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            // Remove "ab" then "ba"
            return calculatescore(s, 'a', 'b', x) +
                   calculatescore(s, 'b', 'a', y);
        } else {
            // Remove "ba" then "ab"
            return calculatescore(s, 'b', 'a', y) +
                   calculatescore(s, 'a', 'b', x);
        }
    }

private:
    int calculatescore(string& s, char first, char second, int points) {
        stack<char> stk;
        int score = 0;

        for (auto ch : s) {
            if (!stk.empty() && stk.top() == first && ch == second) {
                score += points;
                stk.pop();
            } else {
                stk.push(ch);
            }
        }

        string remaining;

        while (!stk.empty()) {
            remaining += stk.top();
            stk.pop();
        }

        reverse(remaining.begin(), remaining.end());

        s = remaining;

        return score;
    }
};
