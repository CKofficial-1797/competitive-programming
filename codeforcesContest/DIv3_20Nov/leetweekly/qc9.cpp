#include <bits/stdc++.h>
using namespace std;

static long long edgeCost(long long n){
    return 4*n*n - n - 4;
}

static long long innerCost(long long n){
    return 5*(n*n - n - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        long long res;
        if(n == 1){
            res = 1;
        }else if(n == 2){
            res = 9;
        }else{
            if(n <= 4) res = edgeCost(n);
            else       res = innerCost(n);
        }

        cout << res << "\n";
    }
    return 0;
}
