class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<long long>products(nums.size(),1);
        long long max_sum=100000LL*1000000000LL;
        for(int i=nums.size()-2;i>=0;i--){
            if(products[i+1]>max_sum/nums[i+1]){
                products[i]=max_sum+1;
            }
            else{
                products[i]=products[i+1]*nums[i+1];
            }
        }
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum==products[i]) return i;
            sum+=nums[i];
        }
        return -1;
    }
};