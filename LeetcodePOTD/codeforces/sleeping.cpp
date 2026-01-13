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
      int n ,k ;
      cin>>n>>k;
      string s;
      cin>>s;
      int cnt =0;
      int awaketill =-1;
      for(int i = 0 ; i<n ;i++){
        if(s[i]=='1'){
            awaketill =max(awaketill,i+k);
        }
        if(i>awaketill)cnt++;
      } 
      cout<<cnt<<"\n"; 
    }
    return 0;
}