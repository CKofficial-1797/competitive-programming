#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int t;
     cin >> t;
    while (t--) {
        int n ;
        
        cin >> n;
        vector<int> a(n),b(n);
        int xorSum=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            // xorSum^=a[i]^i+1;
        }
    // if(xorSum!=0) {
    //     cout<<"NO"<<endl;
    //     continue;
    // }
    b=a;
    // sort(b.begin(), b.end());
    bool flag =false;
    do{
        if(a==b)continue;
        for(int i =1 ; i<n;i++){
            if(a[i-1]+b[i-1]>a[i]+b[i]){
                 flag=false;
                 break;
                }
            }
            flag=true;
        }
    while(!flag && next_permutation(b.begin(), b.end()) );
    for (int i =0 ;i<n-1;i++){
        cout<< b[i]<<" ";
    }
    cout<<b[n-1]<<endl;
    }
    return 0;
}