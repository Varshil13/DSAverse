// DFS code
class Solution {
    private:
    void dfs(int r, int c, vector<vector<int>>&vis,vector<vector<char>>& board , int dr[],int dc[]){
        vis[r][c] = 1;
         int n = board.size();
        int m = board[0].size();


        for(int i =0 ; i < 4 ;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,vis,board,dr,dc);
            }
        }


    }
public:
    void solve(vector<vector<char>>& board) { 
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j = 0 ; j < m ; j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,dr,dc);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                  dfs(n-1,j,vis,board,dr,dc);
            }
            
    }
            for(int i = 0 ; i< n ; i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,dr,dc);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                  dfs(i,m-1,vis,board,dr,dc);
            }
            
    }

    for(int i =0;i<n;i++){
        for(int j = 0 ; j<m;j++){
            if(!vis[i][j] && board[i][j]=='O'){
                board[i][j]='X';

            }

        }
    }
        
    }
};


//BFS code
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        // Check first and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                vis[0][j] = 1;
                q.push({0, j});
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                vis[n - 1][j] = 1;
                q.push({n - 1, j});
            }
        }

        // Check first and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                vis[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }

        // Perform BFS from all border 'O's
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        // Change all unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};



/*
Time and Space Complexity Analysis:
Time Complexity: O(n * m)
Each cell in the n x m grid is visited at most once during the BFS traversal,
 so the overall time taken is proportional to the total number of cells.

Space Complexity: O(n * m)
We use a vis matrix of size n x m to track visited cells and a queue that can 
hold up to O(n * m) cells in the worst case (if all are 'O'). Thus, the space used is also linear in the number of cells.

*/