#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    FAST;

    int n, q;
    cin >> n >> q;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> lg(n+1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;

    static int table[200005][21];

    for(int i = 1; i <= n; i++)
        table[i][0] = a[i];

    for(int k = 1; k <= lg[n]; k++) {
        for(int i = 1; i + (1 << k) - 1 <= n; i++) {
            table[i][k] = min(
                table[i][k-1],
                table[i + (1 << (k-1))][k-1]
            );
        }
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int k = lg[len];
        int ans = min(
            table[l][k],
            table[r - (1 << k) + 1][k]
        );
        cout << ans << '\n';
    }
}
