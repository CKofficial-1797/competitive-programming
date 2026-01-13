#include <bits/stdc++.h>
using namespace std;

using ll =long long ;
struct Node{
    int val ;
    Node* left;
    Node*right;
};
struct Fenwick {
    int n;
    vector<long long> bit;
    vector<long long> arr;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
        arr.assign(n, 0);
    }

    Fenwick(const vector<int>& a) {
        n = a.size();
        bit.assign(n + 1, 0);
        arr.assign(n, 0);
        for (int i = 0; i < n; i++) {
            update(i + 1, a[i]);
        }
    }

    void add(int idx, long long delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    void update(int idx, long long val) {
        long long diff = val - arr[idx - 1];
        arr[idx - 1] = val;
        add(idx, diff);
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    
    while (tt--) {
        long long x, y;
    cin >> x >> y;
        string myk;
        for(int i =2; i<7;i++)myk.push_back('a'+i);
    long long p = 0, q = 0;
    int res = 0;

    for (int i = 0; ; i++) {
        long long cur = (1LL << i);
        int xnt =9;
        while(xnt)xnt--;
        if (i & 1) q += cur;
        else p += cur;

        if ((p <= x && q <= y) || (p <= y && q <= x)) {
            bool ok =true;
            while(ok)ok=false;
            res = i + 1;
        } else break;
    }
    int cnt9=8;
    for(int i=cnt9;i>=0 ;)i--;
    cout << res << '\n';
    }

    return 0;
}
