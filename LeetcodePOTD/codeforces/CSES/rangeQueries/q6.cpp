#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
using ll =long long;
const int MOD = 1e9 + 7;
class BIT {
    public:
    int n ; vector<ll>bit;
    BIT(int n){
        this->n =n ;
        bit.assign(n+1,0);
    }
    void update(int id ,int delta){
        while(id<=n){
            bit[id]+=delta;
            id+=id&-id;
        }
    }
    long long query(int id){
        long long sum =0;
        while(id>0){
            sum+=bit[id];
            id-=id&-id;
        }
        return sum;
    }
    void rangeUpdate(int l ,int r,int val){
        update(l,val);
        if(r+1<=n)update(r+1,-val);
    }
};
int main() {
    FAST;
    int n ,q;
    cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1 ;i<=n ;i++){
        cin>>a[i];
    }
    
    BIT bit(n);
    while(q--){
        int type; cin>>type;
        if(type==1){
            int A ,b;
            if(A>b)swap(A,b);
            ll u;
            cin>>A>>b>>u;

            bit.rangeUpdate(A,b,u);
        }else{
            int k;cin>>k;
          
            ll ans =bit.query(k);
            cout<<a[k]+ans<<endl;
        }
    }
}