class Solution {
 private:
  void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis,
           int n, int m) {
    vis[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      for (int k = 0; k <4 ; k++) {
          int nr = r + dr[k];
          int nc = c + dc[k];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' &&
              vis[nr][nc] == 0) {
            vis[nr][nc] = 1;
            q.push({nr, nc});
          }
        
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] == 0 && grid[i][j] == '1') {
        count++;
          bfs(i, j, grid, vis,n,m);
          
        }
      }
    }
    return count;
  }
};

/*
Time Complexity (TC):
- Each cell is visited at most once.
- For an n x m grid, TC = O(n * m)

Space Complexity (SC):
- vis array: O(n * m)
- BFS queue: O(min(n * m)), in worst case all land cells are connected.
- So, SC = O(n * m)
*/
