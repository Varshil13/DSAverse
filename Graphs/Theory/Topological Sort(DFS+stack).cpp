// C++ implementation of Topological Sort using DFS and stack

class Solution {
private:
    // Helper function to perform DFS traversal
    // node: current node
    // vis: visited array
    // st: stack to store the topological order
    // adj: adjacency list
    void dfs(int node, int vis[], stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1; // Mark current node as visited
        for (auto it : adj[node]) { // Traverse all adjacent nodes
            if (!vis[it]) {
                dfs(it, vis, st, adj); // Recur for unvisited adjacent nodes
            }
        }
        st.push(node); // Push current node to stack after visiting all neighbors
    }

public:
    // Function to return topological ordering of a directed graph
    // V: number of vertices
    // edges: list of directed edges
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Create adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // Add edge u -> v
        }

        int vis[V] = {0}; // Visited array initialized to 0
        stack<int> st;    // Stack to store topological order

        // Call DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Pop elements from stack to get topological order
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};