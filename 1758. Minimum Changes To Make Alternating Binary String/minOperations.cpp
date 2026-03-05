class Solution {
public:
    int minOperations(string s) {
        int zeroFirst = 0; // 0, 1, 0, 1, 0, 1...
        int oneFirst = 0;  // 1, 0, 1, 0, 1, 0...
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) { // even indices should be '0'
                if (s[i] != '0') {
                    zeroFirst++;
                }
            } else { // odd indices should be '1'
                if (s[i] != '1') {
                    zeroFirst++;
                }
            }
        }
        // Calculate mismatches for the pattern starting with '1' using the total length
        oneFirst = s.length() - zeroFirst;
        return min(oneFirst, zeroFirst);
    }
};