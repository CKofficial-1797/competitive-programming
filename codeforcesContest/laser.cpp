#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        long long x, y;
        cin >> n >> m >> x >> y;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<long long> b(m);
        for (int j = 0; j < m; ++j) cin >> b[j];

        cout << (n + m) << '\n';
    }
    return 0;
}
