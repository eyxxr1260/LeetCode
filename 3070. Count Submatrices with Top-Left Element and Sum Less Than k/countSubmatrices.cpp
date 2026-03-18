class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 1. Get sum from the row above (if exists)
                int top = (i > 0) ? grid[i - 1][j] : 0;
                
                // 2. Get sum from the column to the left (if exists)
                int left = (j > 0) ? grid[i][j - 1] : 0;
                
                // 3. Get the overlapping top-left sum (if exists)
                int top_left = (i > 0 && j > 0) ? grid[i - 1][j - 1] : 0;
                
                // Apply the Inclusion-Exclusion Principle and store in-place
                grid[i][j] += top + left - top_left;

                // Check if the current submatrix sum is valid
                if (grid[i][j] <= k) {
                    count++;
                } else {
                    // Pruning: Since all values are >= 0, the sum will only increase to the right.
                    break;
                }
            }
        }
        return count;
    }
};