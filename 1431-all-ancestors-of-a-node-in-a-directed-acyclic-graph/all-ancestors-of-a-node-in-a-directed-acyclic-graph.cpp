class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);  // adjacency list
        vector<int> inDegree(n, 0);  // to store in-degrees of nodes
        
        // Build the graph and calculate in-degrees
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        // To store ancestors
        vector<set<int>> ancestors(n);
        
        // Topological Sort using Kahn's Algorithm (BFS based)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // For each child of the current node
            for (int child : adj[node]) {
                // Add the current node and its ancestors to the child's ancestors
                ancestors[child].insert(node);
                ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());
                
                // Decrease in-degree and add to queue if it's zero
                if (--inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        
        // Convert the set of ancestors to a sorted vector
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        
        return result;
    }
};