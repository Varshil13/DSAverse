class Solution {
public:

   int backtrack(vector<vector<int>>& grid,int row,int col){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() ||  grid[row][col] == 0 )  return 0;
        
         int currGold = grid[row][col];
         grid[row][col] =0;


    int up = backtrack(grid, row - 1, col);
    int down = backtrack(grid, row + 1, col);
    int left = backtrack(grid, row, col - 1);
    int right = backtrack(grid, row, col + 1);
        grid[row][col] = currGold;
       return currGold + max({up, down, left, right});
    }




    int getMaximumGold(vector<vector<int>>& grid) {
        int pathsum = 0;
            for(int j=0;j<grid[0].size();j++){
            for(int i = 0 ;i<grid.size() ;i++){
                if(grid[i][j] > 0){
             int collected = backtrack(grid, i, j);
                pathsum = max(pathsum, collected);
;

                }
             }
        }
       
        return pathsum;


        
    }
};