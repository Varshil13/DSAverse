/*
We started with storing all the positions of zeroes in a vector of pairs.
Then we iterated through the vector and set the entire row and column to zero for each position.
time complexity is O(n*m) where n is the number of rows and m is the number of columns.
Space complexity is O(k) where k is the number of zeroes in the matrix.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>> zeroPositions;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    zeroPositions.push_back({i, j});
                }
            }
        }
        for(auto [r, c] : zeroPositions) {
            for(int j = 0; j < m; j++) matrix[r][j] = 0;  
            for(int i = 0; i < n; i++) matrix[i][c] = 0;  
        }
    }
};
