#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
struct BIT {
    int n ;
    vector<int>bit;
    BIT(int n){
        this->n =n ;
        bit.assign(n+1,0);
    }
    void update(int id ,int val){
        while(id<=n){
            bit[id]+=val;
            id+=id&-id;
        }
    }
    int query(int id){
        int cnt =0;
        while(id>0){
            cnt+=bit[id];
            id-=id&-id;
        }
        return cnt;
    }
    int rangeQ(int l ,int r){
        return query(r)-query(l-1);
    }
};
int main() {
    FAST;
    int n ,q;
    cin>>n>>q;
    vector<int>em(n+1);
    for(int i =1 ;i<=n ;i++)cin>>em[i];
    //we have to do compression 
    vector<int>comp(em.begin()+1,em.end());
   
   vector<tuple<char,int,int>>queries;
    while(q--){
        char type;
        cin>>type;
        if(type=='!'){
            int k,x;
             cin>>k>>x;
            comp.push_back(x);
            queries.push_back({'!',k,x});
        }else{
            int a, b;
            cin>>a>>b;
            queries.push_back({'?',a,b});
            comp.push_back(a);
            comp.push_back(b);
        }
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    int m =comp.size();
    BIT bit(m);
    for (int i = 1; i <= n; i++) {
    int id = lower_bound(comp.begin(), comp.end(), em[i]) - comp.begin() + 1;
    bit.update(id, 1);
}

    for(auto &q : queries){
        char t;
        int a, b;
        tie(t, a, b) = q;
        if(t=='!'){
            int idx =lower_bound(comp.begin(),comp.end(),em[a])-comp.begin()+1;
             int id =lower_bound(comp.begin(),comp.end(),b)-comp.begin()+1;
            em[a]=b;
             bit.update(idx,-1);
            bit.update(id,+1);
        }else{
            int ida =lower_bound(comp.begin(),comp.end(),a)-comp.begin()+1;
            int idb =lower_bound(comp.begin(),comp.end(),b)-comp.begin()+1;
            cout<<bit.rangeQ(ida,idb)<<endl;
        };
    }

}