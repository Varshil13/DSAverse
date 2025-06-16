/*
Given a directed acyclic graph (DAG) with weights, 
the task is to return an array denoting the shortest distance of each node from node 0.

Approach:
1. Create an adjacency list: 
    - The adjacency list is a vector of vectors of pairs, 
      where each pair contains the destination node and the weight of the edge.

2. Perform topological sort using DFS:
    - Use a stack to store nodes in topological order.

3. Initialize a distance array:
    - Set all values to 1e9 (infinity).
    - Set the distance of the source node (0) to 0.

4. Process nodes in topological order:
    - For each node, update the distance of its neighbors 
      if the distance through the current node is less than their current distance.

5. Finalize the result:
    - If a node is unreachable, set its distance to -1.
    - Return the distance array.
*/





class Solution {
private:
// Function to perform topological sort using DFS
    void toposort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                toposort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        // Create an adjacency list from the edges
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        // Perform topological sort
        // for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                toposort(i, adj, vis, st);
            }
        }
        // Initialize distances
        // to all nodes as infinity
        vector<int> dist(V, 1e9);
        // Distance to the source node (0) is 0
        dist[0] = 0;
        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        // Replace unreachable nodes with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
