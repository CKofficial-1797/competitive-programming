#include <bits/stdc++.h>
using namespace std;

int readInt() {
    int x;
    if(!(cin >> x)) return 0;
    return x;
}

long long readLL() {
    long long x;
    cin >> x;
    return x;
}

struct RangeMax {
    int len;
    vector<int> lg;
    vector<vector<long long>> tab;
    void build(const vector<long long>& v) {
        len = v.size();
        lg.assign(len+1, 0);
        for(int i=2;i<=len;i++) lg[i] = lg[i/2] + 1;
        int K = lg[len] + 1;
        tab.assign(K, vector<long long>(len, LLONG_MIN/4));
        for(int i=0;i<len;i++) tab[0][i] = v[i];
        for(int k=1;k<K;k++){
            for(int i=0;i + (1<<k) <= len; ++i){
                tab[k][i] = max(tab[k-1][i], tab[k-1][i + (1<<(k-1))]);
            }
        }
    }
    long long get(int L, int R) const {
        if(L>R) return LLONG_MIN/4;
        int k = lg[R-L+1];
        return max(tab[k][L], tab[k][R-(1<<k)+1]);
    }
};

vector<long long> prefixSums(const vector<long long>& v) {
    int s = v.size();
    vector<long long> p(s+1,0);
    for(int i=0;i<s;i++) p[i+1] = p[i] + v[i];
    return p;
}

long long sumFirst(const vector<long long>& p, int k){
    return p[k];
}

long long sumLast(const vector<long long>& p, int k){
    int total = p.size()-1;
    return p[total] - p[total-k];
}

long long solveOne() {
    int m = readInt();
    long long L = readLL();
    long long R = readLL();
    vector<long long> b(m);
    for(int i=0;i<m;i++) b[i] = readLL();
    sort(b.begin(), b.end());
    auto pref = prefixSums(b);
    vector<long long> Xl(m+1), Xr(m+1), Yl(m+1), Yr(m+1);
    for(int p=0;p<=m;p++){
        Xl[p] = p * L - sumFirst(pref, p);
        Xr[p] = p * R - sumFirst(pref, p);
    }
    for(int q=0;q<=m;q++){
        Yl[q] = sumLast(pref, q) - q * L;
        Yr[q] = sumLast(pref, q) - q * R;
    }
    vector<long long> prefMaxYl(m+1, LLONG_MIN/4);
    long long cur = LLONG_MIN/4;
    for(int q=0;q<=m;q++){
        cur = max(cur, Yl[q]);
        prefMaxYl[q] = cur;
    }
    RangeMax rmq;
    rmq.build(Yr);
    long long bestAns = LLONG_MIN/4;
    for(int p=0;p<=m;p++){
        int qmax = min(p, m-p);
        if(qmax >= 0) bestAns = max(bestAns, Xl[p] + prefMaxYl[qmax]);
        int Lidx = p + 1;
        int Ridx = m - p;
        if(Lidx <= Ridx) bestAns = max(bestAns, Xr[p] + rmq.get(Lidx, Ridx));
    }
    return bestAns;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = readInt();
    while(T--){
        cout << solveOne() << "\n";
    }
    return 0;
}
