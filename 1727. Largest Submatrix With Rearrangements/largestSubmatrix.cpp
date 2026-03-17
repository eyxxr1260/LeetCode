class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int max_area=0;

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }

        for(int i=0;i<m;i++){
            vector<int>height=matrix[i];
            sort(height.begin(),height.end(),greater<int>());

            for(int j=0;j<n;j++){
                int area=height[j]*(j+1);
                max_area=max(max_area, area);
            }
        }
        return max_area;
        
    }
};
