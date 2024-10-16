class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pqmaxi;

        if (a) {
            pqmaxi.push({a, 'a'});
        }

        if (b) {
            pqmaxi.push({b, 'b'});
        }

        if (c) {
            pqmaxi.push({c, 'c'});
        }

        string result = "";

        while (!pqmaxi.empty()) {
            auto [currcount, currchar] = pqmaxi.top();

            pqmaxi.pop();

            if (result.size() >= 2 && result[result.size() - 1] == currchar &&
                result[result.size() - 2] == currchar) {

                if (pqmaxi.empty()) {
                    break;
                }

                auto [nextcount, nextchar] = pqmaxi.top();

                pqmaxi.pop();

                result += nextchar;
                nextcount--;

                if (nextcount) {
                    pqmaxi.push({nextcount, nextchar});
                }

                pqmaxi.push({currcount, currchar});
            } else {
                result += currchar;
                currcount--;

                if (currcount) {
                    pqmaxi.push({currcount, currchar});
                }
            }
        }

        return result;
    }
};