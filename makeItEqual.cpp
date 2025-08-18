#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    FAST;
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        vector<long long> S(n), T(n);
        for (auto &x : S) cin >> x;
        for (auto &x : T) cin >> x;
        
        
        map<long long, int> freq;
        
        for (auto x : S) {
            long long r = x % k;
            freq[r]++;
        }
        
        
        for (auto x : T) {
            long long r = x % k;
            freq[r]--;
        }
        
        
        bool possible = true;
        set<long long> visited;
        
        for (auto& p : freq) {
            long long r = p.first;
            int count = p.second;
            
            if (visited.count(r)) continue;
            
            long long complement = (k - r) % k;
            visited.insert(r);
            visited.insert(complement);
            
            if (r == complement) {
                
                if (count != 0) {
                    possible = false;
                    break;
                }
            } else {
                
                int comp_count = freq[complement];
                if (count + comp_count != 0) {
                    possible = false;
                    break;
                }
            }
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    
    return 0;
}