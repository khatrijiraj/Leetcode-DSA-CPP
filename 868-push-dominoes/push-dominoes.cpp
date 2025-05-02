class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string res;

        int prev = 0;
        for (int i = 1; i < dominoes.size(); i++) {
            if (dominoes[i] == '.') {
                continue;
            }

            int span = i - prev - 1;
            if (prev > 0) {
                res += dominoes[prev];
            }

            if (dominoes[prev] == dominoes[i]) {
                res += string(span, dominoes[prev]);
            } else if (dominoes[prev] == 'L' && dominoes[i] == 'R') {
                res += string(span, '.');
            } else {
                res += string(span / 2, 'R') + string(span % 2, '.') +
                       string(span / 2, 'L');
            }
            prev = i;
        }
        return res;
    }
};