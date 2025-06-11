//for adjencency list 
void dfs(int node, vector<int> adj[] , int vis[] , vector<int> &ls){
    vis[node] = 1;
    ls.push_back[node];
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}


vector <int> dfsOfGraph(int V , vector<int> adj[]){
    int vis[V] = {0};
    int start = 0 ;
    vector<int> ls;
    dfs(start, adj, vis , ls);
    return ls;

    
}

//for adjencency matrix

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    
    for (int i = 0; i < adj.size(); i++) {
        if (adj[node][i] == 1 && !vis[i]) {
            dfs(i,  adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> ls;
    int start = 0;
    dfs(start, adj, vis, ls);
    return ls;
}