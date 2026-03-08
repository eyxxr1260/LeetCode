class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        
        // Double the string to simulate all possible rotations (Type-1 operations)
        string doubled_s = s + s;
        
        // Prepare the two alternating templates of length 2N
        string alt1 = "";
        string alt2 = "";
        for (int i = 0; i < doubled_s.length(); i++) {
            alt1 += (i % 2 == 0) ? '0' : '1';
            alt2 += (i % 2 == 0) ? '1' : '0';
        }
        
        int ans = INT_MAX; 
        int diff1 = 0, diff2 = 0;
        
        // Sliding window over the doubled string
        for (int i = 0; i < doubled_s.length(); i++) {
            
            // Add the incoming character to our differences
            if (doubled_s[i] != alt1[i]) diff1++;
            if (doubled_s[i] != alt2[i]) diff2++;
            
            // Remove the outgoing character from our differences if the window exceeds size N
            if (i >= n) {
                if (doubled_s[i - n] != alt1[i - n]) diff1--;
                if (doubled_s[i - n] != alt2[i - n]) diff2--;
            }
            
            // Once the window reaches exactly size N, we check if we found a new minimum
            if (i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }
        
        return ans;
    }
};