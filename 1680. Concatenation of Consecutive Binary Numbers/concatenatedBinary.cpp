class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans = 0;
        int length = 0;
        for (int i = 1; i <= n; i++) {
            //If i is a power of 2 (1, 2, 4, 8...)
            if ((i & (i - 1)) == 0) { // i = 1、10、100、1000...
                length++;
            }
            //Shift the current answer left by 'length' bits, add 'i', and apply modulo
            ans = ((ans << length) + i) % 1000000007;
        }
        return ans;
    }
};