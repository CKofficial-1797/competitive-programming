#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int c;
        long long s;
        Node *l, *r;
        Node(int _c, long long _s, Node* _l, Node* _r) : c(_c), s(_s), l(_l), r(_r) {}
    };

    vector<Node*> roots;
    vector<int> vals;
    int SZ;

    Node* build(int L, int R){
        if (L == R) return new Node(0,0,nullptr,nullptr);
        int M = (L+R)>>1;
        return new Node(0,0, build(L,M), build(M+1,R));
    }

    Node* upd(Node* nd, int L, int R, int idx, int v){
        if (L == R) return new Node(nd->c + 1, nd->s + v, nullptr, nullptr);
        int M = (L+R)>>1;
        Node* nn = new Node(nd->c + 1, nd->s + v, nd->l, nd->r);
        if (idx <= M) nn->l = upd(nd->l, L, M, idx, v);
        else nn->r = upd(nd->r, M+1, R, idx, v);
        return nn;
    }

    int kth(Node* Lroot, Node* Rroot, int L, int R, int k){
        if (L == R) return L;
        int M = (L+R)>>1;
        int lc = Rroot->l->c - Lroot->l->c;
        if (k <= lc) return kth(Lroot->l, Rroot->l, L, M, k);
        return kth(Lroot->r, Rroot->r, M+1, R, k - lc);
    }

    pair<int,long long> qsum(Node* Lroot, Node* Rroot, int L, int R, int lim){
        if (L > lim) return {0,0};
        if (R <= lim) return {Rroot->c - Lroot->c, Rroot->s - Lroot->s};
        int M = (L+R)>>1;
        auto a = qsum(Lroot->l, Rroot->l, L, M, lim);
        auto b = qsum(Lroot->r, Rroot->r, M+1, R, lim);
        return {a.first + b.first, a.second + b.second};
    }

    vector<vector<int>> stmin, stmax;
    vector<int> lg;

    void buildST(const vector<int>& a){
        int n = a.size();
        int K = lg[n];
        stmin.assign(n, vector<int>(K+1));
        stmax.assign(n, vector<int>(K+1));
        for (int i=0;i<n;i++) stmin[i][0] = stmax[i][0] = a[i];
        for (int j=1;j<=K;j++){
            for (int i=0;i + (1<<j) <= n; i++){
                stmin[i][j] = min(stmin[i][j-1], stmin[i + (1<<(j-1))][j-1]);
                stmax[i][j] = max(stmax[i][j-1], stmax[i + (1<<(j-1))][j-1]);
            }
        }
    }

    bool allEqual(int L, int R){
        int j = lg[R-L+1];
        int mn = min(stmin[L][j], stmin[R - (1<<j) + 1][j]);
        int mx = max(stmax[L][j], stmax[R - (1<<j) + 1][j]);
        return mn == mx;
    }

public:
    vector<long long> minOperations(vector<int>& a, int k, vector<vector<int>>& qs){
        int n = a.size();
        lg.assign(n+1,0);
        for (int i=2;i<=n;i++) lg[i] = lg[i>>1] + 1;

        if (k == 0){
            buildST(a);
            vector<long long> res;
            for (auto &q : qs) res.push_back(allEqual(q[0], q[1]) ? 0 : -1);
            return res;
        }

        vector<int> mod(n);
        for (int i=0;i<n;i++) mod[i] = a[i] % k;
        buildST(mod);

        vals.resize(n);
        for (int i=0;i<n;i++) vals[i] = a[i] / k;
        vector<int> uniq = vals;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
        SZ = uniq.size();

        auto rk = [&](int x){
            return int(lower_bound(uniq.begin(), uniq.end(), x) - uniq.begin());
        };

        roots.clear();
        roots.reserve(n+1);
        roots.push_back(build(0, SZ-1));
        for (int x : vals) roots.push_back(upd(roots.back(), 0, SZ-1, rk(x), x));

        vector<long long> out;
        out.reserve(qs.size());
        for (auto &q : qs){
            int L = q[0], R = q[1];
            if (!allEqual(L, R)) { out.push_back(-1); continue; }
            int len = R - L + 1;
            int pos = (len + 1) / 2;
            int mid_idx = kth(roots[L], roots[R+1], 0, SZ-1, pos);
            long long mid_val = uniq[mid_idx];

            auto left = qsum(roots[L], roots[R+1], 0, SZ-1, mid_idx);
            long long cntL = left.first;
            long long sumL = left.second;
            long long totSum = roots[R+1]->s - roots[L]->s;
            long long totCnt = roots[R+1]->c - roots[L]->c;
            long long cntR = totCnt - cntL;
            long long sumR = totSum - sumL;

            long long ops = (cntL * mid_val - sumL) + (sumR - cntR * mid_val);
            out.push_back(ops);
        }

        return out;
    }
};
