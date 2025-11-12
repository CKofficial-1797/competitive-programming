#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long startRating, threshold, delta;
        int rounds;
        cin >> startRating >> threshold >> delta >> rounds;

        string contestType;
        cin >> contestType;

        long long low = startRating, high = startRating;
        int ratedRounds = 0;

        for (char c : contestType) {
            if (c == '1') {
                ratedRounds++;
                low = max(0LL, low - delta);
                high += delta;
            } else {
                if (low >= threshold) continue;
                ratedRounds++;
                low = max(0LL, low - delta);
                high = min(high, threshold - 1) + delta;
            }
        }

        cout << ratedRounds << '\n';
    }
    return 0;
}
