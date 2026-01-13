#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
using ll =long long;
class SegTree{
    int n ; vector<ll>tree;
public:
    SegTree(vector<long long >&a){
       n =a.size()-1;
        tree.assign(4*n,0LL);
        build(1,1,n,a);
    }
    void build(int idx,int l , int r,vector<long long>&a){
        if(l==r){
            tree[idx]=a[l];return;
        }
        int mid =l+(r-l)/2;
        build(2*idx,l,mid,a);
        build(2*idx+1,mid+1,r,a);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
    void update(int idx ,int l ,int r,int pos,long long  delta){
        if(l==r){
            tree[idx]=delta;return;
        }
        int mid =l+(r-l)/2;
        if(pos<=mid) update(2*idx,l,mid,pos,delta);
        else update(2*idx+1,mid+1,r,pos,delta);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);

    }
    long long query(int idx ,int l ,int r,int ql,int qr){
        if(qr<l || r<ql)return 1e18;
        if(ql<=l && r<=qr) return tree[idx];
        int mid =l+(r-l)/2;
        return min(query(2*idx,l,mid,ql,qr),query(2*idx+1,mid+1,r,ql,qr));
    }
    void pointUpdate(int idx,int val){
        update(1,1,n,idx,val);
    }
    long long pointQ(int l, int r){
        return query(1,1,n,l,r);
    }
};
int main() {
    FAST;
    int n , q;
    cin>>n>>q;
    vector<long long >a(n+1);
    for(int i =1; i<=n;i++)cin>>a[i];
    SegTree seg(a);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int k,u;cin>>k>>u;
            seg.pointUpdate(k,u);
        }else{
            int a,b;
            cin>>a>>b;
            long long  mini = seg.pointQ(a,b);
            cout<<mini<<endl;
        }
    }
    return 0;
}