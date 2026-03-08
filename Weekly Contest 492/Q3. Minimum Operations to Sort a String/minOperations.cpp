class Solution {
public:
    int minOperations(string s) {
        // Check if it is already sorted
        bool isSorted = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] > s[i + 1]) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) return 0;
        
        //Impossible case
        if (s.length() == 2) return -1;
        
        // Find the absolute minimum and maximum characters
        char minL = 'z', maxL = 'a';
        for (char c : s) {
            minL = min(minL, c);
            maxL = max(maxL, c);
        }
        
        // Can be done in 1 operation
        if (s[0] == minL || s[s.length() - 1] == maxL) return 1;
        
        // Count occurrences of min and max characters
        int minCount = 0, maxCount = 0;
        for (char c : s) {
            if (c == minL) minCount++;
            if (c == maxL) maxCount++;
        }
        
        // Worst case
        if (maxL == s[0] && minL == s[s.length() - 1] && minCount == 1 && maxCount == 1) {
            return 3;
        }

        // All other cases take 2 operations
        return 2;
    }
};