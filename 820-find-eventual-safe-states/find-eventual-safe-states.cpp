class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<vector<int>> reversegraph(nodes);
        vector<int> outdegree(nodes);

        for (int i = 0; i < nodes; i++) {
            for (auto& it : graph[i]) {
                reversegraph[it].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }

        queue<int> qt;

        for (int i = 0; i < reversegraph.size(); i++) {
            if (outdegree[i] == 0) {
                qt.push(i);
            }
        }

        vector<int> result;

        while (!qt.empty()) {
            int index = qt.front();
            qt.pop();
            result.push_back(index);

            for (auto it : reversegraph[index]) {
                outdegree[it]--;
                if (outdegree[it] == 0) {
                    qt.push(it);
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};