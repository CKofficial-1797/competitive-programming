#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCount;
    cin >> testCount;
    while (testCount--) {
        int length;
        string str;
        cin >> length >> str;

        char finalChar = str[length - 1];
        int movesNeeded = 0;

        for (int i = 0; i < length; i++) {
            if (str[i] != finalChar) {
                movesNeeded++;
            }
        }

        cout << movesNeeded << '\n';
    }

    return 0;
}
