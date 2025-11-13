#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        long long bad =
            ( (x & y) & (~z) ) |
            ( (x & z) & (~y) ) |
            ( (y & z) & (~x) );

        if (bad) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
