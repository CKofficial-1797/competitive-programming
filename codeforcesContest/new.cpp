#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        int neg = 0;
        for (int i = 0; i < n; ++i) {
            int v; cin >> v;
            if (v == -1) ++neg;
        }

        int forceSum = max(0, neg - n / 2);     
        int after = neg - forceSum;            
        int ans = forceSum + (after % 2);       
        cout << ans << '\n';
    }
    return 0;
}
