class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if (mat.size() < 1)
            return 0;
        vector<int> rowCount(mat.size(), 0), colCount(mat[0].size(), 0);
        // Step 1: Precompute the number of 1s in each row and column
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int ans = 0;
        // Step 2: Check each cell against the precomputed counts
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (rowCount[i] == 1 && colCount[j] == 1 && mat[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};