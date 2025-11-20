#include <iostream>
#include <vector>

using namespace std;

static long long absoluteValue(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        long long first = v[0], last = v[n-1];

        if (first == -1 && last == -1) {
            first = 0;
            last = 0;
        } else if (first == -1) {
            first = last;
        } else if (last == -1) {
            last = first;
        }

        v[0] = first;
        v[n-1] = last;

        for (int i = 0; i < n; i++) {
            if (v[i] == -1) v[i] = 0;
        }

        long long answer = absoluteValue(v[n-1] - v[0]);
        cout << answer << "\n";

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << v[i];
        }
        cout << "\n";
    }

    return 0;
}
