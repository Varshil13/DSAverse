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


    //     int V = graph.size();
    //     vector<int> vis(V, 0);
    //     vector<int> pathVis(V, 0);
    //     vector<int> checked(V, 0);

    //     vector<int> safeNodes;

    //     for (int i = 0; i < V; i++) {
    //         if (!vis[i]) {
    //             dfsCheck(i, graph, vis, pathVis, checked);
    //         }
    //     }

    //     for (int i = 0; i < V; i++) {
    //         if (checked[i] == 1) {
    //             safeNodes.push_back(i);
    //         }
    //     }

    //     return safeNodes;
  
            /*
            In this part of the code, we are solving with the topological sort algorithm.

            1. We reverse the directions of the graph first, also calculating the indegree of each node.
               (This is because we want to find the nodes which are not part of any cycle. So, we reverse
                the graph and then find the nodes with 0 indegree, which means they are not part of any cycle.)

            2. We then perform the normal topological sort algorithm:
               - Use a queue to push the nodes with indegree 0.
               - Pop each element and push it into the answer vector.
               - Iterate to the nodes it is pointing to and reduce their indegree by 1.
               - If indegree becomes 0, push it into the queue again.

            3. Finally, we sort the answer vector and return it.
            */

            int n = graph.size();
            vector<vector<int>> adjrev(n);

            // Reverse the graph and calculate indegrees
            vector<int> indegree(n, 0);
            for (int i = 0; i < n; i++) {
                for (auto it : graph[i]) {
                    adjrev[it].push_back(i);
                    indegree[i]++;
                }
            }

            // Topological sort using Kahn's algorithm
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> ans;

            // Process the queue
            while (!q.empty()) {
                int x = q.front();
                ans.push_back(x);
                q.pop();
                for (auto i : adjrev[x]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }

            // Sort the answer vector
            sort(ans.begin(), ans.end());
            return ans;
        }
