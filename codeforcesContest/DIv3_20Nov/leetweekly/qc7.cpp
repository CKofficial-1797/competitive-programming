#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<ll,ll> read_counts(int n){
    unordered_map<ll,ll> M;
    M.reserve(n * 2);
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        M[x] += 1;
    }
    return M;
}

vector<ll> init_over(const unordered_map<ll,ll>& M, ll K){
    vector<ll> v;
    v.reserve(16);
    for(auto &p : M) if(p.second > K) v.push_back(p.first);
    return v;
}

ll run_rounds(unordered_map<ll,ll>& cnt, ll K){
    ll rounds = 0;
    vector<ll> cur = init_over(cnt, K);
    while(!cur.empty()){
        ++rounds;
        unordered_map<ll,ll> bump;
        bump.reserve(cur.size()*2 + 4);
        for(ll key : cur){
            ll c = cnt[key];
            if(c <= K) continue;
            ll move = c - 1;
            cnt[key] = 1;
            bump[key + 1] += move;
        }
        for(auto &p : bump) cnt[p.first] += p.second;
        cur.clear();
        cur.reserve(bump.size());
        for(auto &p : bump) if(cnt[p.first] > K) cur.push_back(p.first);
    }
    return rounds;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n; ll k;
        cin >> n >> k;
        auto freq = read_counts(n);
        cout << run_rounds(freq, k) << '\n';
    }
    return 0;
}
