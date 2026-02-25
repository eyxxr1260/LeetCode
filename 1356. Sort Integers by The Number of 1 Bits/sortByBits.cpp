class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bin_a = __builtin_popcount(a);
            int bin_b = __builtin_popcount(b);
            return bin_a != bin_b ? bin_a < bin_b : a < b;
        });

        return arr;
    }
};