#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
 struct Fenwick {
    int n ; vector<long long >bit;
    vector<long long >arr;
    Fenwick(vector<long long >&a){
        n =a.size();
        bit.assign(n+1,0);
        for(int i =0 ; i<n ;i++){
            add(i+1,a[i]);
        }
        arr=a;
    }
    void add(int id , long long  delta){
        while(id<=n){
            bit[id]+=delta;
            id+=id&-id;
        }
    }
    void update(int id,long long  val){
        long long  delta = val -arr[id-1];
        add(id,delta);
        arr[id-1]=val;
    }
    long long  query(int id){
        long long sum =0;
        while(id>0){
            sum+=bit[id];
            id-=id&-id;
        }
        return sum;
    }
    long long rangeQ(int l ,int r){
        return query(r)-query(l-1);
    }


 };

int main() {
    FAST;
    int n,t;
     cin >> n>> t;
     vector<long long >a(n);
     for(int i =0 ;i<n ; i++){
        cin>>a[i];
     }
     Fenwick f(a);
    while (t--) {
       int first ,second;
       long long third;
       cin>>first>>second>>third; 
       if(first==1){
            f.update(second,third);
       }else{
            cout<<f.rangeQ(second,third)<<endl;
       }
    }
    return 0;
}