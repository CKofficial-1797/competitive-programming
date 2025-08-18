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
        int n ; int cnt0=0, cnt1=0;
        cin>>n;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp==-1) cnt0++;
            else cnt1++;
        }
        int operations =0;
        
            if(cnt0>cnt1){
               n%2==0? operations += n/2-cnt1 : operations += n/2-cnt1+1;
               cnt0 = n/2;
            } 
             if(cnt0%2!=0){
                operations++;
                cnt0--;
                cnt1++;
            }

            cout<<operations<<endl;
    }
    return 0;
}