class Solution {
    // 1. Disjoint Set Union (DSU) structure to track connected components
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return false;
            parent[rootY] = rootX;
            return true;
        }
    };

    // 2. The Validation Function
    bool check(int target, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int edges_count = 0; 
        
        // Phase 1: Mandatory edges
        for (const auto& e : edges) {
            if (e[3] == 1) {
                // If a mandatory edge cannot reach the target, the whole tree fails
                if (e[2] < target) return false; 
                if (dsu.unite(e[0], e[1])) edges_count++;
            }
        }
        
        // Phase 2: Free optional edges (already meet target)
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= target) {
                if (dsu.unite(e[0], e[1])) edges_count++;
            }
        }
        
        // Phase 3: Upgradable optional edges
        int used_k = 0;
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < target && (long long)e[2] * 2 >= target) {
                if (dsu.unite(e[0], e[1])) {
                    edges_count++;
                    used_k++; 
                    if (used_k > k) return false; // Exceeded budget
                }
            }
        }
        
        // Successfully formed a spanning tree?
        return edges_count == n - 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // Edge Case 1: Can the graph be connected at all?
        DSU dsu_global(n);
        int connected = 0;
        for (const auto& e : edges) {
            if (dsu_global.unite(e[0], e[1])) connected++;
        }
        if (connected < n - 1) return -1; 
        
        // Edge Case 2: Do the mandatory edges form an invalid cycle?
        DSU dsu_must(n);
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!dsu_must.unite(e[0], e[1])) return -1; 
            }
        }
        
        // 3. Binary Search for the Maximum Possible Stability
        int left = 1, right = 200000; // Max strength is 100k, upgraded max is 200k
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            
            if (check(mid, n, edges, k)) {
                ans = mid;       // Valid! Save answer and try to push higher
                left = mid + 1;  
            } else {
                right = mid - 1; // Invalid, lower the standard
            }
        }
        
        return ans;
    }
};