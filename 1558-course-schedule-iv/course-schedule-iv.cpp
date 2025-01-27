class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        // using kahn algo topological sorting

        // for storing graph adjaceny list
        unordered_map<int, vector<int>> graph;

        // storing indegree
        vector<int> indegree(numCourses, 0);

        // creating graph & updating indegree
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        // will process each node having indegree == 0
        queue<int> qt;

        // if indegree == 0 pushing in queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                qt.push(i);
            }
        }

        // to optimise searching storing in set in a map for each node to find
        // the preqrequiste
        unordered_map<int, unordered_set<int>> mpp;

        // processing nodes
        while (!qt.empty()) {
            int node = qt.front();
            qt.pop();

            // exploring all of its nodes will reduce indegree by one and update
            // the prerequisite
            for (auto adj : graph[node]) {
                // this node is obvio a preq of its next connected node through
                // directed edge
                mpp[adj].insert(node);

                // since it is preq of its next then all of its preq will also
                // be of its next basically transistivity realation
                for (auto preq : mpp[node]) {
                    mpp[adj].insert(preq);
                }

                // reducting the indegree by one and if it becomes 0 then
                // pushing in queue
                indegree[adj]--;
                if (indegree[adj] == 0) {
                    qt.push(adj);
                }
            }
        }

        // final array fro result
        vector<bool> result;

        for (auto it : queries) {
            int u = it[0];
            int v = it[1];
            // if preq map have u in it then true else false
            result.push_back(mpp[v].contains(u));
        }

        return result;
    }
};