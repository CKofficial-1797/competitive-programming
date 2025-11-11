#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    int N = 2 * n; 

    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    
    vector<int> pmin0(n), pmax0(n);
    pmin0[0] = a[0][0];
    pmax0[0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        pmin0[i] = min(pmin0[i - 1], a[0][i]);
        pmax0[i] = max(pmax0[i - 1], a[0][i]);
    }

    
    vector<int> smin1(n), smax1(n);
    smin1[n - 1] = a[1][n - 1];
    smax1[n - 1] = a[1][n - 1];
    for (int i = n - 2; i >= 0; --i) {
        smin1[i] = min(smin1[i + 1], a[1][i]);
        smax1[i] = max(smax1[i + 1], a[1][i]);
    }

    
    vector<int> minR(N + 2, N + 2); 
    for (int c = 0; c < n; ++c) {
        int Lc = min(pmin0[c], smin1[c]);
        int Rc = max(pmax0[c], smax1[c]);
        minR[Lc] = min(minR[Lc], Rc);
    }

    
    vector<int> r_star(N + 2, N + 2);
    for (int l = N; l >= 1; --l) {
        r_star[l] = min(r_star[l + 1], minR[l]);
    }

    
    long long ans = 0;
    for (int l = 1; l <= N; ++l) {
        
        int r_min = max(l, r_star[l]);
        
        
        if (r_min <= N) {
            ans += (N - r_min + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}