class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1000000007LL;
        
        // dp[i][j][0]: ways to use i zeros, j ones, ending in 0
        // dp[i][j][1]: ways to use i zeros, j ones, ending in 1
        vector<vector<vector<long long>>> dp(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        // Initialization: Pure 0 arrays and Pure 1 arrays
        for (int i = 1; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                
                // Construct sequences ending in 0 by appending 'k' zeros to a sequence ending in 1
                for (int k = 1; k <= min(i, limit); k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                }
                
                // Construct sequences ending in 1 by appending 'k' ones to a sequence ending in 0
                for (int k = 1; k <= min(j, limit); k++) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};