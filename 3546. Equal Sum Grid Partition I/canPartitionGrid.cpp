class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Step 1: Calculate the total sum of the grid
        long long total = 0;
        for (auto& row : grid) {
            for (int x : row) {
                total += x;
            }
        }
        
        // If the total sum is odd, it's impossible to divide it equally into integer sums
        if (total % 2 != 0) {
            return false;
        }

        long long target = total / 2;
        long long sum = 0;
        
        // Step 2: Try Horizontal Cuts
        // Loop up to m-1 to guarantee the bottom section is non-empty
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
            }
            // Check if the current top section equals the target
            if(sum == target) return true;
        }
        
        // Reset sum for vertical cuts
        sum = 0;
        
        // Step 3: Try Vertical Cuts
        // Loop up to n-1 to guarantee the right section is non-empty
        for(int j = 0; j < n - 1; j++){
            for(int i = 0; i < m; i++){
                sum += grid[i][j];
            }
            // Check if the current left section equals the target
            if(sum == target) return true;
        }
        
        return false;
    }
};