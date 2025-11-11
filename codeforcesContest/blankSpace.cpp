#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int longest = 0, current = 0;

        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x == 0) {
                current++;
                longest = max(longest, current);
            } else {
                current = 0;
            }
        }
        cout << longest << '\n';
    }
    return 0;
}
