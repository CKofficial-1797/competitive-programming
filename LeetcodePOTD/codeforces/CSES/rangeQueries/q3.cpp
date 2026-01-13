#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
struct segTree{
    int n ;vector<long long>tree;
    segTree(vector<long long>&a){
        this->n =a.size()-1;
        tree.assign(4*n,0);
        build(1,1,n,a);
    }
    void build(int id , int l ,int r ,vector<long long>&a){
        if(l==r){
            tree[id]=a[l];return ;
        }
        int mid = l+(r-l)/2;
        build(2*id,l,mid,a);
        build(2*id+1,mid+1,r,a);
        tree[id]=tree[2*id]+tree[2*id+1];
    }
    void update(int id , int l, int r,int pos ,long long val){
        if(l==r){
            tree[id]=val;return;
        }
        int mid =l+(r-l)/2;
        if(pos<=mid) update(2*id,l,mid,pos,val);
        else update(2*id+1,mid+1,r,pos,val);
        tree[id]=tree[2*id]+tree[2*id+1];
    }
    long long query(int id ,int l ,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l && r<=qr) return tree[id];
        int mid =l+(r-l)/2;
        return query(2*id,l,mid,ql,qr) +query(2*id+1,mid+1,r,ql,qr);
    }
    void pointUpdate(int pos,long long val){
        update(1,1,n,pos,val);
    }
    long long rangeSum(int l ,int r){
        return query(1,1,n,l,r);
    }
};
int main() {
    FAST;
    int n , q;
    cin>>n>>q;
    vector<long long >a(n+1);
    for(int i =1 ;i<=n ;i++)cin>>a[i];
    segTree sg(a);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int k ; long long u;
            cin>>k>>u;
            sg.pointUpdate(k,u);
        }else{
            int l,r ;
            cin>>l>>r;
            cout<<sg.rangeSum(l,r)<<endl;
        }
    }
    return 0;
}