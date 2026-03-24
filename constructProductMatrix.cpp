class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD=12345;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n, vector<int>(m));

        long long prod=1;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans[i][j]=prod;
                prod=(prod*(grid[i][j]%MOD))%MOD;
            }
        }
        prod=1;

        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                ans[i][j]=(ans[i][j]*prod)%MOD;
                prod=(prod*(grid[i][j]%MOD))%MOD;
            }
        }
        return ans;
    }
};