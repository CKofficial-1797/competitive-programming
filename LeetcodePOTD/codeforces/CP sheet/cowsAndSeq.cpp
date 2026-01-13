#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
const int MAXN =200005;
long long bit[MAXN];
int base[MAXN]; //to store the value by oper 2
int n;
struct BIT{
  void update (int id , int delta ){
        while(id>0){
            bit[id]-=delta;
            id -=id&-id;
        }
    }
    double query (int id){
        double s =0 ;
        while(id<=n){
            s+=bit[id];
            id+=id&-id;
        }
        return s;
    }
};
BIT ds;
long long add[MAXN];
int main() {
    FAST;
    int t;
     cin >> t;
      n =t;
     int sz =1;
     long long ts =0;
     base[1]=0;
     add[1]=0;
    while (t--) {
        int op ;
        cin>>op;
        if(op==1){
            int a , x;
            cin>>a >>x;
            ds.update(a,x);
            ts+=(a*x);
        }
        else if(op==2){
            int k ;cin>>k;
            sz++;
            base[sz]=k;
            ts+=k;
        }
        else{
            long long lazy =ds.query(sz);
            ts -= (base[sz]+lazy);
            ds.update(sz-1,lazy);
            ds.update(sz,-lazy);
            sz--;
        }
        cout<<fixed<<setprecision(6)<<(double)ts/sz<<endl;
        
    }
    return 0;
}