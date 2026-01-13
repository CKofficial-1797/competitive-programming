#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r;
};

// Helper to check if value exists in range
bool has_val(const vector<int>& a, int l, int r, int v) {
    for (int i = l; i <= r; i++) {
        if (a[i] == v) return true;
    }
    return false;
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<Query> t1, t2;
    vector<bool> t1_mask(n + 1, false);
    vector<bool> t2_mask(n + 1, false);

    for (int i = 0; i < q; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            t1.push_back({l, r});
            for (int j = l; j <= r; j++) t1_mask[j] = true;
        } else {
            t2.push_back({l, r});
            for (int j = l; j <= r; j++) t2_mask[j] = true;
        }
    }

    // Fill with 1e9 initially (safe large value)
    vector<int> arr(n + 1, 1e9);

    // 1. Satisfy min(l...r) = k
    // We need at least one 'k' in the range.
    // We can only place 'k' at indices NOT forbidden by Type 2 (MEX=k forbids k).
    for (auto& qry : t1) {
        if (has_val(arr, qry.l, qry.r, k)) continue;

        for (int i = qry.l; i <= qry.r; i++) {
            if (!t2_mask[i]) {
                arr[i] = k;
                break; 
            }
        }
    }

    // 2. Satisfy MEX(l...r) = k
    // We need 0, 1, ... k-1 in the range.
    // Sort to process intervals left-to-right (optional, but good for greedy).
    sort(t2.begin(), t2.end(), [](Query a, Query b) {
        return a.r < b.r;
    });

    for (int v = 0; v < k; v++) {
        for (auto& qry : t2) {
            if (has_val(arr, qry.l, qry.r, v)) continue;

            // Greedy: Place 'v' at the rightmost valid position.
            // Valid = Not covered by Type 1 (must be >= k) and currently empty.
            for (int i = qry.r; i >= qry.l; i--) {
                if (!t1_mask[i] && arr[i] == 1e9) {
                    arr[i] = v;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}