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
        int n ,k ,x;
        cin >> n >> k >> x;
        if(x!=1){
            cout<<"YES"<<endl;
            cout<<n<<endl;
            while(n--){
                cout<<1<<" ";
            }
            cout<<endl;
        }else{
            int rem =n%k;
            if(rem%2!=0){
                if(k<=2){
                    cout<<"NO"<<endl;
                }else{
                    int cnt2 =n/k;
                    cout<<"YES"<<endl;
                    cout<<cnt2+rem/2<<endl;
                    while(cnt2--){
                        cout<<k<<" ";
                    }
                    int i =1;
                    while(i*2+2<rem){
                        cout<<2<<" ";
                        i++;
                    }
                    cout<<3<<endl;
                }
                
            
            }else{
                cout<<"YES"<<endl;
                
                int cnt =n/k;
                cout<<cnt+rem/2<<endl;
                while(cnt--){
                    cout<<k<<" ";
                }
                while(rem){
                    cout<<2<<" ";
                    rem-=2;
                };
                cout<<endl;
            }
        }
    }
    return 0;
}