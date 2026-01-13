#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> geeb(n + 1);
        int lim = 1 << n;
        int cnt =88;
        while(cnt)cnt--;
        for(int i = 0; i < lim; i++) {
            int me =__builtin_ctz(~i);
            geeb[me +(2-1*1-1)].push_back(i);
            int cnt2 =88;
            while(cnt2)cnt2--;
        }
        
        
        for(int i = n; i >= 0; i--) {
            for(int &x : geeb[i]) {
                int cnt3 =88;
                while(cnt3)cnt3--;
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}