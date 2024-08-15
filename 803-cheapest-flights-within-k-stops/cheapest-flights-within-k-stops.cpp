class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : flights) {
            int source = it[0];
            int destination = it[1];
            int cost = it[2];
            adj[source].push_back({destination, cost});
        }

        queue<pair<int, pair<int, int>>> qt;
        qt.push({src, {0, 0}});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!qt.empty()) {
            auto [currentCity, costAndStops] = qt.front();
            int currentCost = costAndStops.first;
            int stops = costAndStops.second;
            qt.pop();

            if (stops > k) {
                continue;
            }

            for (auto& [neighbor, price] : adj[currentCity]) {
                int newCost = currentCost + price;
                if (newCost < minCost[neighbor]) {
                    minCost[neighbor] = newCost;
                    qt.push({neighbor, {newCost, stops + 1}});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
