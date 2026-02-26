class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;
        
        // Traverse from the least significant bit up to the second bit.
        for (int i = s.length() - 1; i > 0; i--) {
            // Calculate the actual value of the current bit including the carry.
            int bit = (s[i] - '0') + carry;
            
            if (bit == 1) {
                // The current value is odd.
                // We must add 1 (generating a carry) and then divide by 2.
                // This requires 2 steps.
                steps += 2;
                carry = 1; 
            } else {
                // The current value is even (bit is either 0 or 2).
                // If bit is 0, carry remains 0.
                // If bit is 2 (1 + carry), it becomes 10 in binary, leaving a carry of 1.
                // Dividing by 2 takes exactly 1 step.
                steps += 1;
            }
        }
        
        // Account for the final carry applied to the most significant bit s[0].
        return steps + carry;
    }
};