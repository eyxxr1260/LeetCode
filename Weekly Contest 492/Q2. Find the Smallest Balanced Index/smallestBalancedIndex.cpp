class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<long long> products(nums.size(), 1);
        long long max_sum = 100000LL * 1000000000LL;
        
        //Precompute right products safely from right to left
        for(int i = nums.size() - 2; i >= 0; i--){
            // Overflow prevention using division
            if(products[i + 1] > max_sum / nums[i + 1]){
                products[i] = max_sum + 1; // Cap at an unreachable value
            }
            else{
                products[i] = products[i + 1] * nums[i + 1];
            }
        }
        
        //Calculate left sums and find the balanced index
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum == products[i]) return i;
            sum += nums[i];
        }
        
        return -1;
    }
};