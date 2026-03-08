class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        if (nums.size() == 0)
            return "";
        // Initialize an answer string of length n, filled with '0's
        string ans(nums[0].length(), '0');
        for (int i = 0; i < nums.size(); i++) {
            // Iterate through the array and flip the diagonal characters
            ans[i] = (nums[i][i] == '1') ? '0' : '1';
        }
        return ans;
    }
};