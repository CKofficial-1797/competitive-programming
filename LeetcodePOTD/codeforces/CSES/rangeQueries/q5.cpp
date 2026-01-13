#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int n ,q;
    cin>>n>>q;
    vector<int>a(n+1);
    for(int i =1 ;i<=n ;i++)cin>>a[i];
    vector<int>preXor(n+1,0);
    for(int i =1; i<=n ;i++){
        preXor[i]=preXor[i-1]^a[i];
    }
    while(q--){
        int a ,b;
        cin>>a>>b;
        int rangeXor =preXor[b]^preXor[a-1];
        cout<<rangeXor<<endl;
    }
    return 0;
}