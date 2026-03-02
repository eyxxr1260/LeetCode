class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n, 0);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    count++; // 數有連續幾個0
                } else
                    break;
            }
            zeros[i] = count;
        }
        int steps = 0;
        // 第 k 列，需要至少 n - 1 - k 個 0
        for (int k = 0; k < n; k++) {
            int target = n - 1 - k;
            int l = k;
            while (l < n && zeros[l] < target) {
                l++;
            }
            if (l == n)
                return -1;
            int temp = zeros[l];
            while (l > k) {
                zeros[l] = zeros[l - 1]; // grid[l] = grid[l - 1];
                l--;
                steps++;
            }
            zeros[k] = temp;
        }
        return steps;
    }
};