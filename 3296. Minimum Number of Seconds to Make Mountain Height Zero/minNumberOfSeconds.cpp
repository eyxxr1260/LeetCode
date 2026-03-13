class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left=1;
        long long right=1e16;
        long long ans=right;

        auto check=[&](long long T){
            long long total_dug=0;
            for(long long w: workerTimes){
                long long x=(long long)(sqrtl(2.0L*T/w));
                while(w*x*(x+1)/2>T){
                    x--;
                }
                while(w*(x+1)*(x+2)/2<=T){
                    x++;
                }
                total_dug+=x;
                if(total_dug>=mountainHeight) return true;

            }
            return total_dug>=mountainHeight;
        };
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(check(mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};