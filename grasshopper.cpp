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
        int x,k;
        cin>>x>>k;
        if(x<k|| x%k!=0){
            cout<<1<<endl;
            cout<<x<<endl;
            continue;
        }
        for(int i=x;i>0;i--){
            if(i%k!=0){
                cout<<2<<endl;
                cout<<i<<" "<<x-i<<endl;
                break;
            }
            
        }
    }
    return 0;
}