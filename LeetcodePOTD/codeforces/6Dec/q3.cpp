#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mirror_val(int h, int L) {
    uint64_t v = h;
    int t = h >> (L % 2);
    for (int i = 0; i < L / 2; ++i) v = (v << 1) | ((t >> i) & 1);
    return v <= INT_MAX ? (int)v : -1;
}

vector<int> gen_pals() {
    vector<int> out;
    out.push_back(0);
    for (int L = 1; L <= 31; ++L) {
        int hl = (L + 1) / 2;
        int s = 1 << (hl - 1);
        int e = (1 << hl) - 1;
        for (int h = s; h <= e; ++h) {
            int v = mirror_val(h, L);
            if (v >= 0) out.push_back(v);
        }
    }
    sort(out.begin(), out.end());
    out.erase(unique(out.begin(), out.end()), out.end());
    return out;
}

int nearest_diff(const vector<int>& pals, int x) {
    auto it = lower_bound(pals.begin(), pals.end(), x);
    ll best = LLONG_MAX;
    if (it != pals.end()) best = min(best, llabs((ll)*it - x));
    if (it != pals.begin()) best = min(best, llabs((ll)*prev(it) - x));
    return (int)best;
}

class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        static vector<int> pals = gen_pals();
        vector<int> ans;
        ans.reserve(nums.size());
        for (int x : nums) ans.push_back(nearest_diff(pals, x));
        return ans;
    }
};
