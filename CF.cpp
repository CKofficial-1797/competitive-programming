#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> a(n);
    std::vector<std::vector<int>> pos_to_vals(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        pos_to_vals[0].push_back(i);
    }

    long long b_prev = 0;
    for (int i = 0; i < n; ++i) {
        long long current_b = b[i];
        int i_one_based = i + 1; 
        
        long long req_prev_pos_ll = (long long)i_one_based - (current_b - b_prev);
        int req_prev_pos = (int)req_prev_pos_ll;

        int val_to_use = pos_to_vals[req_prev_pos].back();
        pos_to_vals[req_prev_pos].pop_back();

        a[i] = val_to_use;

        pos_to_vals[i_one_based].push_back(val_to_use);
        
        b_prev = current_b;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}