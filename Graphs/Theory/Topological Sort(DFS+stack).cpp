class Solution {
    private:
     void dfs(int node; int vis[] , stack<int>& st, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it , vis ,st,adj);
        }
        st.push(node);
    
        
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
for (auto edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
}

        int vis[V] = {0};
        stack<int> st;
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                dfs(i, vis ,st ,adj);
                
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};