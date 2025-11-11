#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isGuaranteedWin(vector<int> arr) {
    sort(arr.begin(), arr.end()); 
    for (int j = 1; j + 1 < (int)arr.size(); j += 2) {
        if (arr[j] != arr[j + 1]) return false; 
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << (isGuaranteedWin(a) ? "YES" : "NO") << '\n';
    }
    return 0;
}
