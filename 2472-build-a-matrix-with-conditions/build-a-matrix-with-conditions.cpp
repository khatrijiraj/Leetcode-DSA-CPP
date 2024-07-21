class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>>& conditions, int& k) {
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> graph(k + 1);

        for (auto it : conditions) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            ++indegree[v];
        }

        queue<int> qt;

        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                qt.push(i);
            }
        }

        vector<int> result;
        while (!qt.empty()) {
            int node = qt.front();
            qt.pop();
            result.push_back(node);

            for (auto it : graph[node]) {
                if (--indegree[it] == 0) {
                    qt.push(it);
                }
            }
        }

        if (result.size() == k) {
            return result;
        } else {
            return vector<int>{};
        }
    }

public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(rowConditions, k);
        vector<int> colOrder = topologicalSort(colConditions, k);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        vector<vector<int>> result(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rowOrder[i] == colOrder[j]) {
                    result[i][j] = rowOrder[i];
                    break;
                }
            }
        }

        return result;
    }
};