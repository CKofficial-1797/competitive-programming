#include <iostream>

using namespace std;


int countConfigurations(int legs) {
    if (legs % 2 != 0) return 0;
    return legs / 4 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    if (!(cin >> testCases)) return 0;

    while (testCases--) {
        int legs;
        cin >> legs;
        cout << countConfigurations(legs) << '\n';
    }
    return 0;
}
