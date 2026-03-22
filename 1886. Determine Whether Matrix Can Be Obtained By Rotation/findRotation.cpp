class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // A matrix can only have 4 unique rotation states (0, 90, 180, 270 degrees)
        for(int step=0;step<4;step++){
            if(mat==target) return true;

            for(int i=0;i<mat.size();i++){
                // j starts from i to avoid double-swapping back to the original
                for(int j=i;j<mat[0].size();j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            // Reverse each row horizontally
            for(int i=0;i<mat.size();i++){
                reverse(mat[i].begin(),mat[i].end());
            }
        }
        return false;
    }
};