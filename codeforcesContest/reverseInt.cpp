#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        cout << (s == t ? "YES\n" : "NO\n");
    }

    return 0;
}
