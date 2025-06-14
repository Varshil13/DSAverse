class Solution {
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis,
                  vector<int>& pathVis, vector<int>& checked) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, graph, vis, pathVis, checked)) {
                    checked[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                checked[node] = 0;
                return true;
            }
        }

        checked[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> checked(V, 0);

        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, checked);
            }
        }

        for (int i = 0; i < V; i++) {
            if (checked[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
