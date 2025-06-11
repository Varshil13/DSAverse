class Solution {
public:


void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[node][i] == 1 && !vis[i]) {
            dfs(i, adj, vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<int> vis(V, 0);
    int start = 0;
    int t = 0;
    for(int i = 0; i < V ;i++ ){
        if(vis[i] == 0){
            t++;
            dfs(i, isConnected, vis);
        }

    }
    return t;
   
    }
};

  