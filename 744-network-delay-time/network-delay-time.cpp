class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v, w});
        }

        vector<int> distance(n + 1, INT_MAX);

        distance[k] = 0;

        // {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > distance[node]) {
                continue;
            }

            for (auto& it : graph[node]) {
                int newdist = dist + it.second;
                if (newdist < distance[it.first]) {
                    distance[it.first] = newdist;
                    pq.push({newdist, it.first});
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i < distance.size(); i++) {
            if (distance[i] == INT_MAX) {
                return -1;
            }
            maxi = max(maxi, distance[i]);
        }

        return maxi;
    }
};