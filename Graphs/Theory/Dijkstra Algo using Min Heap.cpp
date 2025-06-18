// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i= 0 ; i < V ; i++){
            dist[i] = 1e9;
        }
        
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int  adjNode = it.first;
                int edgeWeight = it.second;
                
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
            
            
        }
        return dist;
            
        
    
    }
};