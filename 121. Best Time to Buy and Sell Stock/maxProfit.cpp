class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int curr=prices[0];
        int maxP=0;
        while(i<prices.size()){
            if(prices[i]<curr){
                curr=prices[i];
            }
            //Calculate profit if sold today, and update maxP if it's the highest so far
            maxP=max(maxP,prices[i]-curr);
            i++;
        }
        return maxP;
    }
};