#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int lastKept = -k;
        int answer = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '1') continue;
            if (i - lastKept >= k) {
                ++answer;
                lastKept = i;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
