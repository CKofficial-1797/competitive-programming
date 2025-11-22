#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Stack stores the indices of the roots of the current disjoint components.
    // We maintain the invariant that p[st[k]] is strictly decreasing.
    vector<int> st;
    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++) {
        // When we encounter a new node p[i], it can serve as a parent 
        // for any existing component roots that are smaller than p[i].
        
        int component_root = -1;
        
        while (!st.empty() && p[st.back()] < p[i]) {
            int u = st.back();
            st.pop_back();
            
            // Connect the old root u to the new node i
            // This is valid because u appeared before i (u is from stack) and value(u) < value(i)
            edges.push_back({p[u], p[i]});
            
            // Greedy Logic:
            // The component we just merged now includes p[i].
            // To connect this new larger component to future nodes on the right,
            // we need a representative value 'v' such that v < future_node.
            // We keep the SMALLEST value (the first one we popped) as the representative
            // to maximize our ability to connect to future nodes.
            if (component_root == -1) {
                component_root = u;
            }
        }

        // If we merged components, push the smallest representative back.
        // Otherwise, p[i] is a new isolated component, so push i.
        if (component_root != -1) st.push_back(component_root);
        else st.push_back(i);
    }

    // If the stack has exactly 1 element left, all nodes are connected.
    if (st.size() == 1) {
        cout << "Yes\n";
        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}