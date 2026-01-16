#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') p.push_back(i);
    }

    // guaranteed at least one '1', so p is never empty
    int mx = 0;
    int k = p.size();
    
    // find the largest gap between consecutive 1s cyclically
    for (int i = 0; i < k; i++) {
        int u = p[i];
        int v = p[(i + 1) % k];
        int gap;

        if (v > u) {
            gap = v - u - 1;
        } else {
            // wrap around case
            gap = n - u + v - 1;
        }
        mx = max(mx, gap);
    }
    cout << mx << "\n";
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