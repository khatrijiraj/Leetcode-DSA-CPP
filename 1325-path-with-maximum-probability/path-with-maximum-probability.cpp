class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;

        while (!pq.empty()) {
            auto [current_prob, node] = pq.top();
            pq.pop();
            if (node == end_node) {
                return current_prob;
            }

            for (auto& [neighbor, prob] : graph[node]) {
                double new_prob = current_prob * prob;
                if (new_prob > probabilities[neighbor]) {
                    probabilities[neighbor] = new_prob;
                    pq.push({new_prob, neighbor});
                }
            }
        }

        return 0.0;
    }
};
