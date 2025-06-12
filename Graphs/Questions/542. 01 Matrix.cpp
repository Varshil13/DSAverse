class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n  = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int> >vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){      
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int st = q.front().second;
            q.pop();
            dist[r][c]=st;
            for(int d =0 ; d < 4 ; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr<n && nc<m && nr>=0 && nc>=0 && vis[nr][nc] == 0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},st+1});
                }
            }

        }

        return dist;






    }
};
//     /// Total Time Complexity = O(N * M)
//     /// Total Space Complexity = O(N * M) for: dist[][] and vis[][]          