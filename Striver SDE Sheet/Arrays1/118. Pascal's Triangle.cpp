/*
  Generates Pascal's Triangle up to the given number of rows.
 
  The function handles the cases where the number of rows is 1 or 2 by manually creating the initial rows.
  For additional rows, it uses nested loops to construct each row:
    - The first and last elements of each row are set to 1.
    - The internal elements are calculated by summing the elements at the current index and the previous index from the previous row.
    - Each completed row is added to the answer vector.
 
  Time Complexity: O(n^2)
  Space Complexity: O(n)
  */

  class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n = numRows;
        if (n == 1)
            return {{1}};
        if (n > 1) {
            ans.push_back({1});
            ans.push_back({1, 1});
            if (n == 2) {
                return ans;
            }
        }

        for (int i = 2; i < n; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            for (int x = 1; x < i; x++) {
                row[x] = ans[i - 1][x] + ans[i - 1][x - 1];
            }
            ans.push_back(row);
        }

        return ans;
    }
};