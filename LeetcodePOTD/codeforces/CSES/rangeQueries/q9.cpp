#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18;

struct SegTree {
    int n;
    vector<ll> t;

    SegTree(int n) : n(n) {
        t.assign(4 * n, INF);
    }

    void update(int node, int l, int r, int pos, ll val) {
        if (l == r) {
            t[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(node << 1, l, mid, pos, val);
        else
            update(node << 1 | 1, mid + 1, r, pos, val);

        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }

    ll query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return INF;
        if (ql <= l && r <= qr)
            return t[node];
        int mid = (l + r) >> 1;
        return min(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    SegTree leftSeg(n), rightSeg(n);

    // build trees
    for (int i = 1; i <= n; i++) {
        leftSeg.update(1, 1, n, i, p[i] - i);
        rightSeg.update(1, 1, n, i, p[i] + i);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k;
            ll x;
            cin >> k >> x;
            p[k] = x;
            leftSeg.update(1, 1, n, k, x - k);
            rightSeg.update(1, 1, n, k, x + k);
        } else {
            int k;
            cin >> k;
            ll ans = min(
                leftSeg.query(1, 1, n, 1, k) + k,
                rightSeg.query(1, 1, n, k, n) - k
            );
            cout << ans << '\n';
        }
    }
}
