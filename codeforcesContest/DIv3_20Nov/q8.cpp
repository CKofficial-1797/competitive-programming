#include <bits/stdc++.h>

using namespace std;

// The problem specifies modulo 10^9 + 3
const long long MOD = 1000000003;
const int MAXF = 2000005; // Sufficient buffer for factorials

long long fact[MAXF];
long long invFact[MAXF];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXF; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long min_ops = -1;
    vector<int> best_ks;

    // b_i <= 10^6, so 2^20 is approx 10^6. k beyond 21 is unnecessary/invalid.
    for (int k = 0; k <= 22; k++) {
        long long current_add_ops = 0;
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            long long val = a[i] * (1LL << k);
            if (val > b[i]) {
                possible = false;
                break;
            }
            long long diff = b[i] - val;
            // Additions from Slot 0 (weight 2^k)
            current_add_ops += (diff >> k);
            // Additions from Slots 1..k (weights 2^{k-1}..1) -> Popcount
            current_add_ops += __builtin_popcountll(diff & ((1LL << k) - 1));
        }

        if (!possible) break; // Larger k will only make a[i]*2^k bigger

        long long total_ops = k + current_add_ops;

        if (min_ops == -1 || total_ops < min_ops) {
            min_ops = total_ops;
            best_ks.clear();
            best_ks.push_back(k);
        } else if (total_ops == min_ops) {
            best_ks.push_back(k);
        }
    }

    long long total_ways = 0;

    for (int k : best_ks) {
        long long ways_k = 1;
        
        // --- Slot 0 (Weight 2^k) ---
        long long L0 = 0;
        for (int i = 0; i < n; i++) {
            long long diff = b[i] - a[i] * (1LL << k);
            long long count = diff >> k;
            L0 += count;
            // Multinomial denominator: count!
            // Since min_ops is small, count will be small. 
            if (count < MAXF) {
                ways_k = (ways_k * invFact[count]) % MOD;
            } else {
                // Should not happen for optimal k, but safe fallback
                // If count >= MOD, invFact is 0 effectively or invalid logic
            }
        }
        
        // Multinomial numerator: L0!
        if (L0 < MAXF) {
            ways_k = (ways_k * fact[L0]) % MOD;
        } else {
            // If L0 >= MOD, factorial is 0 mod MOD
            ways_k = 0;
        }

        // --- Slots 1 to k (Weights 2^{k-1} ... 1) ---
        // In these slots, each number contributes 0 or 1 addition.
        // Denominator is 1! or 0!, which is 1. We only need Numerator (Sum_counts!).
        vector<int> slot_counts(k + 1, 0);
        for (int i = 0; i < n; i++) {
            long long diff = b[i] - a[i] * (1LL << k);
            long long rem = diff & ((1LL << k) - 1);
            for (int j = 1; j <= k; j++) {
                if ((rem >> (k - j)) & 1) {
                    slot_counts[j]++;
                }
            }
        }

        for (int j = 1; j <= k; j++) {
             ways_k = (ways_k * fact[slot_counts[j]]) % MOD;
        }

        total_ways = (total_ways + ways_k) % MOD;
    }

    cout << min_ops << " " << total_ways << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}