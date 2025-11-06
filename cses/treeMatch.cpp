#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

vector<vector<int>> adj;
vector<int> visited;
int ans = 0;

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        if (!visited[u] && !visited[v]) {
            visited[u] = visited[v] = 1;
            ans++;
        }
    }
}

int main() {
    FAST;
    int t;
    cin >> t;
    adj.assign(t+1, {});
    visited.assign(t+1, 0);

    for (int i = 0; i < t-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    cout << ans << endl;
}
