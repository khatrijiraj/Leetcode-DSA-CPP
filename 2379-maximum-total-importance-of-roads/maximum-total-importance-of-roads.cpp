class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        vector<pair<int, int>> cityDegrees;

        for (int i = 0; i < n; ++i) {
            cityDegrees.emplace_back(degree[i], i);
        }

        sort(cityDegrees.begin(), cityDegrees.end(), greater<pair<int, int>>());

        vector<int> importance(n);

        for (int i = 0; i < n; ++i) {
            importance[cityDegrees[i].second] = n - i;
        }

        long long totalImportance = 0;

        for (const auto& road : roads) {
            totalImportance += importance[road[0]] + importance[road[1]];
        }

        return totalImportance;
    }
};