class Solution {
   private:
    void dfs(int sr, int sc, vector<vector<int>>& answer,
             vector<vector<int>>& image, int color, int dr[], int dc[],
             int inicolor, int n, int m) {
        answer[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                image[nr][nc] == inicolor && answer[nr][nc] != color) {
                dfs(nr, nc, answer, image, color, dr, dc, inicolor, n, m);
            }
        }
    }

   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> answer = image;
        int inicolor = image[sr][sc];
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int n = image.size();
        int m = image[0].size();
        dfs(sr, sc, answer, image, color, dr, dc, inicolor, n, m);
        return answer;
    }
};