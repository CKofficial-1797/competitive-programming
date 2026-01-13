#include <bits/stdc++.h>
using namespace std;

int readInt() {
    int z; 
    cin >> z;
    return z;
}

vector<int> makeFreq(int n) {
    vector<int> f(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        if(x >= 0 && x <= n) f[x]++;
    }
    return f;
}

long long calcDel(const vector<int> &f) {
    long long r = 0;
    int m = f.size() - 1;
    for(int v = 0; v <= m; v++) {
        int c = f[v];
        if(c == 0) continue;
        if(c >= v) r += (c - v);
        else r += c;
    }
    return r;
}

long long handle() {
    int n = readInt();
    auto f = makeFreq(n);
    return calcDel(f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = readInt();
    while(t--) cout << handle() << "\n";
    return 0;
}
