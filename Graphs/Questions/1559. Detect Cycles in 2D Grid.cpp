class Solution {
 public:
  bool containsCycle(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j]) {
          queue<tuple<int, int, int, int>> q;
          q.push({i, j, -1, -1});
          vis[i][j] = 1;
          while (!q.empty()) {
            auto [r, c, pr, pc] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
              int nr = r + dr[d];
              int nc = c + dc[d];
              if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                  grid[nr][nc] == grid[r][c]) {
                if (vis[nr][nc] != 1) {
                  q.push({nr, nc, r, c});
                  vis[nr][nc] = 1;
                } else if ((nr != pr || nc != pc)) {
                  return true;
                }
              }
            }
          }
        }
      }
    }
    return false;
  }
};