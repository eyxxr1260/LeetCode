class Solution {
public:
    int minOperations(string s) {
        bool isSorted = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] > s[i + 1]) {
                isSorted = false;
                break;
            }
        }
        if (isSorted)
            return 0;
        if (s.length() == 2)
            return -1;
        char minL = 'z', maxL = 'a';
        for (char c : s) {
            minL = min(minL, c);
            maxL = max(maxL, c);
        }
        if (s[0] == minL || s[s.length() - 1] == maxL)
            return 1;
        int minCount = 0, maxCount = 0;
        for(char c:s){
            if(c==minL)minCount++;
            if(c==maxL)maxCount++;
        }
        if (maxL == s[0] && minL == s[s.length() - 1] && minCount == 1 && maxCount == 1)
            return 3;

        return 2;
    }
};