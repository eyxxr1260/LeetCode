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

        // Base cases: Pure 0 arrays and Pure 1 arrays up to the limit
        for (int i = 1; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }

        // Fill the DP table using the optimized O(1) transitions
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                
                // --- Building sequences ending in 0 ---
                // Blindly add a '0' to previous states
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                
                // Subtract the exact violators if we exceed the limit
                if (i > limit) {
                    // Note: + MOD is strictly required to handle negative results in C++
                    dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + MOD) % MOD;
                }

                // --- Building sequences ending in 1 ---
                // Blindly add a '1' to previous states
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                
                // Subtract the exact violators if we exceed the limit
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + MOD) % MOD;
                }
            }
        }

        // The final answer is the sum of valid arrays ending in 0 and ending in 1
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};