#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const ll MOD = 1000000007LL;
        int n = s.size();

        vector<int> pos, d;
        pos.reserve(n);
        d.reserve(n);

        for (int i = 0; i < n; i++) {
            int v = s[i] - '0';
            if (v) {
                pos.push_back(i);
                d.push_back(v);
            }
        }

        int m = d.size();
        vector<ll> p10(m + 1);
        p10[0] = 1;
        for (int i = 1; i <= m; i++) p10[i] = (p10[i-1] * 10) % MOD;

        vector<ll> pnum(m), ps(m);
        for (int i = 0; i < m; i++) {
            pnum[i] = ((i ? pnum[i-1] : 0) * 10 + d[i]) % MOD;
            ps[i] = d[i] + (i ? ps[i-1] : 0);
        }

        vector<int> out;
        out.reserve(queries.size());

        for (auto &q : queries) {
            int L = q[0], R = q[1];

            int l = lower_bound(pos.begin(), pos.end(), L) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), R) - pos.begin() - 1;

            if (l > r) {
                out.push_back(0);
                continue;
            }

            int len = r - l + 1;
            ll x = pnum[r];
            if (l) x = (x - pnum[l-1] * p10[len]) % MOD;
            if (x < 0) x += MOD;

            ll sm = ps[r] - (l ? ps[l-1] : 0);
            ll res = (x * (sm % MOD)) % MOD;

            out.push_back((int)res);
        }

        return out;
    }
};
