#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int n,t;
    cin >>n>> t;
    vector<int>a(n);
    vector<long long >prefix(n+1,0);
    for(int i=1 ; i<=n;i++){
        cin>>a[i];
        prefix[i]=a[i]+prefix[i-1];
    };

    while (t--) {
        int a ,b;
        cin>>a>>b;
        long long sum =prefix[b]-prefix[a-1];
        cout<<sum<<endl;
    };
    return 0;
}