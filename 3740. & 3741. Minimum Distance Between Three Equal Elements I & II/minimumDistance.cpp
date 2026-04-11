class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if (nums.size() < 3)
            return -1;
        int n = nums.size();

        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }
        int minD = INT_MAX;
        bool found = false;
        for (auto& pair:map) {
            if (pair.second.size() < 3)
                continue;
            found = true;
            vector<int> &idx = pair.second;
            for (int j = 0; j+2 < idx.size(); j++) {
                if (minD > 2 * (idx[j + 2] - idx[j]))
                    minD = 2 * (idx[j + 2] - idx[j]);
            }
        }
        return found?minD:-1;
    }
};