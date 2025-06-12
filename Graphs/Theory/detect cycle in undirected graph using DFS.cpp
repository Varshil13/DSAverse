class Solution {
    private:
    
    bool dfs(int node, int parent, vector<int> vis[] ,vector<int> adj[]){
        vis[node] = 1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,node,vis,adj) == true){
                    return truel;
                }
                else if(adjnode != parent){
                    return true;
                }
                
            }
        }
        return false;
    }
    
    public: 
    bool isCycle(int v , vector<int> adj[]){
        int vis[v] = {0};
        
        for(int i = 0 ; i < adj.size();i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj) == true ) return true;
            }
        }
        return false;
    }
}