class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int MAX_VAL=100005;
        vector<bool> prime(MAX_VAL,true);
        prime[0]=false;
        prime[1]=false;

        for(int i=2;i*i<MAX_VAL;i++){
            if(prime[i]){
                for(int j=i*i;j<MAX_VAL;j+=i){
                    prime[j]=false;
                }
            }
        }

        long long total_op=0;

        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(i%2==0){
                while(num<MAX_VAL && !prime[num]){
                    num++;
                }
            }
            else{
                while(num<MAX_VAL && prime[num]){
                    num++;
                }
            }
            total_op+=(num-nums[i]);
        }
        return total_op;
    }
};