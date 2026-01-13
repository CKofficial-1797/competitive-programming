#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
using ll =long long ;
struct Pt{
    int x , v;
};
struct BIT{
    int n ;
    vector<ll>bit;
    BIT(int n){
        this->n =n;
        bit.resize(n+1,0);
    }
    void update(int id , ll val){
        while(id<=n){
            bit[id]+=val;
            id+=id&-id;
        }
    }
    ll query(int id){
        ll s =0;
        while(id>0){
            s+=bit[id];
            id-=id&-id;
        }
        return s;
    }
};

int main() {
    FAST;
    int n ; cin>>n ;
    vector<Pt>p(n);
    vector<int>vs; // for coordinate compression 
    for(int i =0 ;i<n ;i++)cin>>p[i].x;
     for(int i =0 ;i<n ;i++){
        cin>>p[i].v;
        vs.push_back(p[i].v);
     }
     //sort by position firdt 
     sort(p.begin(),p.end(),[](Pt &a , Pt &b){
        return a.x<b.x;
     });
     //compress
     
     sort(vs.begin(),vs.end());
     vs.erase(unique(vs.begin(),vs.end()),vs.end());
     int m =vs.size();
     BIT bitSum(m),bitCnt(m);

     long long ans =0 ;
     for(int i =0 ;i<n ; i++){
        int id = lower_bound(vs.begin(),vs.end(),p[i].v)-vs.begin()+1;
        long long c = bitCnt.query(id);
        //how many points on left have v<=current v;
        long long s = bitSum.query(id);
        //prefix till now ;
        ans+= (c*p[i].x-s);
        bitSum.update(id,p[i].x);
        bitCnt.update(id,1);
     }
     cout<<ans<<endl;
     return 0;
    
}