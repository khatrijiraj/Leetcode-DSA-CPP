class Solution {
private:
    int bfs(int n, vector<vector<int>>& graph) {
        vector<int> distance(n, INT_MAX);

        queue<int> qt;

        qt.push(0);

        distance[0] = 0;

        while (!qt.empty()) {
            int foq = qt.front();
            qt.pop();

            for (auto it : graph[foq]) {
                if (distance[foq] + 1 < distance[it]) {
                    distance[it] = distance[foq] + 1;
                    qt.push(it);
                }
            }
        }

        return distance[n - 1];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);

        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }

        vector<int> result;

        for (auto it : queries) {
            graph[it[0]].push_back(it[1]);
            result.push_back(bfs(n, graph));
        }

        return result;
    }
};