class Solution {
private:
    void dfs(int i, int n, vector<int>& result) {
        if (i > n) {
            return;
        }

        result.push_back(i);

        for (int j = 0; j < 10; j++) {
            if (i * 10 + j > n) {
                break;
            }
            dfs(i * 10 + j, n, result);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, result);
        }
        return result;
    }
};