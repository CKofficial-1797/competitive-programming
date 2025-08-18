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
        int n;
        cin >> n;
        // vector<int> a(n);
        int diff = INT_MAX;
        bool flag =false;
        int first=-1 ,second;
        for (int i = 0; i < n; i++) {
            cin >> second;
            if (first!=-1) {
                if(second < first) {
                    cout << 0 << endl;
                    flag = true;
                    break;
                    
                }
                diff = min(diff, (second - first)/2+1);

            }
            first = second;
        }
        if(flag)continue;
        cout << diff << endl;
    }
    return 0;
}