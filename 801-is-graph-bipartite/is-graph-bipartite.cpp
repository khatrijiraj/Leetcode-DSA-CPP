class Solution {

private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int col, int i) {
        color[i] = col;

        for (auto it : graph[i]) {
            if (color[it] == -1) {
                if (dfs(graph, color, !col, it) == false) {
                    return false;
                }
            } else if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();

        vector<int> color(nodes, -1);

        for (int i = 0; i < nodes; i++) {
            if (color[i] == -1) {
                if (dfs(graph, color, 0, i) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};