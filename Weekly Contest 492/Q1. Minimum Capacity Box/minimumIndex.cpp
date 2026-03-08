class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=-1;
        int min_num=INT_MAX;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize && min_num>capacity[i]){
                min_num=capacity[i];
                ans=i;
            }
        }
        return ans;
    }
};