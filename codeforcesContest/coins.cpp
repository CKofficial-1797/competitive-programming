#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        bool ok;
        if (k % 2 == 0) {
            ok = (n % 2 == 0);
        } else {
            ok = (n % 2 == 0) || (n >= k);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
