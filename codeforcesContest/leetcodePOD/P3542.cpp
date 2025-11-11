#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
    struct DSU {
        vector<int> parent, size;
        DSU(int n): parent(n), size(n, 1) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int x) {
            while (x != parent[x]) x = parent[x] = parent[parent[x]];
            return x;
        }
        void unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

public:
    int minOperations(vector<int>& nums) {
        const int n = (int)nums.size();
        map<int, vector<int>, greater<int>> byValue; 
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0) byValue[nums[i]].push_back(i);

        if (byValue.empty()) return 0;

        DSU dsu(n);
        vector<char> active(n, 0);  
        int ops = 0;

        for (auto &kv : byValue) {
            const vector<int>& idxs = kv.second;

            
            for (int idx : idxs) {
                active[idx] = 1;
                if (idx > 0 && active[idx - 1]) dsu.unite(idx, idx - 1);
                if (idx + 1 < n && active[idx + 1]) dsu.unite(idx, idx + 1);
            }

           
            unordered_set<int> roots;
            roots.reserve(idxs.size() * 2 + 1);
            for (int idx : idxs) roots.insert(dsu.find(idx));
            ops += (int)roots.size();
        }
        return ops;
    }
};
