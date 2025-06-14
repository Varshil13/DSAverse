class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        vector<int> adj[V];
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // Directed graph
        }

        // Step 2: Prepare visited arrays
        int vis[V] = {0};
        int pathVis[V] = {0};

        // Step 3: DFS to check for cycles
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }

        return false;
    }
};
