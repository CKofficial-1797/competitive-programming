#include <bits/stdc++.h>

using namespace std;

// Solves one test case
void solve() {
    int n, q;
    cin >> n >> q;
    
    // Store all the ranges we need to check
    vector<pair<int, int>> ranges(q);
    for (int i = 0; i < q; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    
    int max_mex = 0;
    
    // Iterate through each given range, query it, and find the max
    for (int i = 0; i < q; ++i) {
        // Ask the judge for the MEX of this range
        cout << "? " << ranges[i].first << " " << ranges[i].second << endl;
        
        int res;
        cin >> res; // Read the judge's response
        
        max_mex = max(max_mex, res);
    }
    
    // Print the final answer
    cout << "! " << max_mex << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}