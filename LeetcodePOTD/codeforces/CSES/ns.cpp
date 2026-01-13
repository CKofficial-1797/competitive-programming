#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int i, long long v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }

    long long sum(int i) {
        long long s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // find smallest index such that prefix sum >= target
    int lower_bound(long long target) {
        int pos = 0;
        long long curr = 0;

        // highest power of two <= n
        for (int pw = 1 << 20; pw > 0; pw >>= 1) {
            if (pos + pw <= n && curr + bit[pos + pw] < target) {
                curr += bit[pos + pw];
                pos += pw;
            }
        }
        return pos + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> h(n + 1);
    BIT bit(n);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        bit.add(i, h[i]);
    }

    while (m--) {
        long long x;
        cin >> x;

        if (bit.sum(n) < x) {
            cout << 0 << " ";
            continue;
        }

        int idx = bit.lower_bound(x);
        cout << idx << " ";

        // reduce capacity at idx
        bit.add(idx, -x);
    }

    cout << "\n";
    return 0;
}
