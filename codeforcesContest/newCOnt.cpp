#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;
using ll = long long;

class CircularMaxPairSum {
    vector<ll> values;

public:
    void readInput(int count) {
        values.resize(count);
        for (int i = 0; i < count; ++i) cin >> values[i];
    }

    int findMaxIndex() const {
        int best = 0;
        for (int i = 1; i < (int)values.size(); ++i) {
            if (values[i] > values[best]) best = i;
        }
        return best;
    }

    vector<ll> rotatedFromMax() const {
        int n = values.size();
        vector<ll> out;
        out.reserve(n);
        int p = findMaxIndex();
        for (int i = p + 1; i < n; ++i) out.push_back(values[i]);
        for (int i = 0; i <= p; ++i) out.push_back(values[i]);
        return out;
    }

    ll compute() const {
        if (values.size() <= 1) return 0;
        vector<ll> seq = rotatedFromMax();
        vector<ll> st;
        ll res = 0;

        for (ll cur : seq) {
            while (!st.empty() && st.back() <= cur) {
                ll mid = st.back();
                st.pop_back();
                if (!st.empty()) res += min(st.back(), cur);
                else res += cur;
            }
            st.push_back(cur);
        }

        while (st.size() > 1) {
            ll x = st.back();
            st.pop_back();
            res += st.back();
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;
        CircularMaxPairSum solver;
        solver.readInput(n);
        cout << solver.compute() << '\n';
    }
    return 0;
}
