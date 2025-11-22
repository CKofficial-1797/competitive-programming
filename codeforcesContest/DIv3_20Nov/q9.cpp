#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        long long b;
        cin >> n >> m >> b;
        vector<int> vals;
        vals.reserve(max(0, m - 1));
        for (int x = 2; x <= m; ++x) {
            int cnt = 0;
            int t = x;
            while (t % b == 0) { t /= b; ++cnt; }
            vals.push_back(cnt);
        }
        sort(vals.begin(), vals.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < n - 1 && i < (int)vals.size(); ++i) ans += vals[i];
        cout << ans << '\n';
    }
    return 0;
}
