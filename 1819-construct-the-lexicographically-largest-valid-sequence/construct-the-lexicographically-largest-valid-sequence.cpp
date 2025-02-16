class Solution {
private:
    bool solve(int i, vector<int>& result, vector<bool>& used, int n) {
        if (i == result.size()) {
            return true;
        }

        if (result[i] != 0) {
            return solve(i + 1, result, used, n);
        }

        for (int num = n; num >= 1; num--) {
            if (used[num]) {
                continue;
            }

            used[num] = true;
            result[i] = num;

            if (num == 1) {
                if (solve(i + 1, result, used, n)) {
                    return true;
                }
            } else if (i + num < result.size() && result[i + num] == 0) {
                result[i + num] = num;
                if (solve(i + 1, result, used, n)) {
                    return true;
                }
                result[i + num] = 0;
            }
            result[i] = 0;
            used[num] = false;
        }

        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        solve(0, result, used, n);

        return result;
    }
};