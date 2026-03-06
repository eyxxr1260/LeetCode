class Solution {
public:
    bool checkOnesSegment(string s) {
        
        // Solution 1: State Tracking
        /*------------------------------------------
        bool flag = false; // true if we have seen a '0'
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') {
                flag = true;
            }
            else if (s[i] == '1' && flag == true) {
                return false;
            }
        }
        return true;
        ------------------------------------------*/

        // Solution 2: Substring Search
        //------------------------------------------
        // string::npos is returned if "01" is not found
        return s.find("01") == string::npos; 
        //------------------------------------------
    }
};