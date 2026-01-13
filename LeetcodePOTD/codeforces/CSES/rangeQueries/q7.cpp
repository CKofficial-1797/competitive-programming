#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
class SEG{
     int n ; vector<int>tree;
             void build(int id ,int l ,int r , vector<int>&a){
        if(l==r){
            tree[id]=a[l];return;
        }
        int mid =l+(r-l)/2;
        build(2*id,l,mid,a);
        build(2*id+1,mid+1,r,a);
        tree[id]=max(tree[2*id],tree[2*id+1]);
     }
    //   int query(int id ,int l ,int r,int ql,int qr){
    //     if(r<ql || l>qr) return INT_MIN;
    //     if(l>=ql && r<=qr) return tree[id];
    //     int mid = l+(r-l)/2;
    //     return max(query(2*id,l,mid,ql,qr),query(2*id+1,mid+1,r,ql,qr));

    //   }
     int findFirst (int idx ,int l ,int r, int need){
        if(tree[idx]<need) return 0;
        if(l==r) return l;
        int mid =(l+r)/2;
        if(tree[idx*2]>=need) return findFirst(idx*2,l,mid,need);
        else return findFirst(idx*2+1,mid+1,r,need);
     }
      void update(int id ,int l,int r,int pos,int val){
        if(l==r){
            tree[id]=val; return ;
        }
       int mid =l+(r-l)/2;
       if(pos<=mid) update(2*id,l,mid,pos,val);
       else update(2*id+1,mid+1,r,pos,val);
       tree[id]=max(tree[2*id],tree[2*id+1]);
      }
     
    public:
        
        SEG(vector<int>&a){
            n =a.size()-1;
            tree.assign(4*n,0);
            build(1,1,n,a);
        }

       int assign(int need, vector<int>&h){
        if(tree[1]<need)return 0;
        int pos =findFirst(1,1,n,need);
        h[pos]-=need;
        update(1,1,n,pos,h[pos]);
        return pos;
       }
};
int main() {
    int n ,m;
    cin>>n>>m;
    vector<int>h(n+1);
    for(int i =1;i<=n ;i++)cin>>h[i];
    SEG seg(h);
    while(m--){
        int r;
        cin>>r;
        cout<<seg.assign(r,h)<<" ";
    }
    cout<<endl;

}