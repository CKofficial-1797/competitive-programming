#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> pures, bads;
    vector<pair<int, int>> safe;
    vector<bool> used(n + 1, false);

    for (int i = 3; i * 2 <= n; i += 2) {
        safe.push_back({2 * i, i});
        used[2 * i] = true;
        used[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        if (i % 2 == 0) pures.push_back(i);
        else bads.push_back(i);
    }

    vector<int> res;
    for (int p : pures) {
        res.push_back(p);
        if (!bads.empty()) {
            res.push_back(bads.back());
            bads.pop_back();
        }
    }

    for (auto& p : safe) {
        res.push_back(p.first);
        res.push_back(p.second);
    }

    while (!bads.empty()) {
        res.push_back(bads.back());
        bads.pop_back();
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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