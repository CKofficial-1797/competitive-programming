#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static inline void addOp(vector<pair<int,int>>& ops, int l, int r) {
    if (l > r) swap(l, r);
    if (l < r && r - l >= 2) {                 
        if (ops.empty() || ops.back() != make_pair(l, r))
            ops.emplace_back(l, r);
    }
}

vector<pair<int,int>> solveOne(int n, const vector<int>& p, const string& s) {
    int pos1 = -1, posN = -1;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 1) pos1 = i + 1;
        if (p[i] == n) posN = i + 1;
    }

    
    if (s[0] == '1' || s[n-1] == '1' || s[pos1-1] == '1' || s[posN-1] == '1')
        return {}; 

    vector<pair<int,int>> ops;
    addOp(ops, pos1, posN);      
    addOp(ops, 1, pos1);          
    addOp(ops, 1, posN);
    addOp(ops, pos1, n);          
    addOp(ops, posN, n);

   
    sort(ops.begin(), ops.end());
    ops.erase(unique(ops.begin(), ops.end()), ops.end());

    // cap: guaranteed ≤ 5 by construction
    return ops;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        string s; cin >> s;

        auto ops = solveOne(n, p, s);
        if (ops.empty()) {
            cout << -1 << '\n';
            continue;
        }
        cout << ops.size() << '\n';
        for (auto [l, r] : ops) cout << l << ' ' << r << '\n';
    }
    return 0;
}
