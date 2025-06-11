vector <int> bfsOfGraph(int V , vector<int> adj[]){
    
    int vis[V] = {0};
    vis[0] = 1;
    
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    
    while(!q.empty()){
        int node = q.front();
         q.pop();
        bfs.push_back(node);
        
        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] == 1;
                q.push(it);
            }
        }
    }
    return bfs;
     

    /// Total Time Complexity = O(V + 2E)
    ///Total Space COmplexity = O(V) for: vis[] array bfs vector queue






    
    
    
    
    
}