#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int main() {
    FAST;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0), parent(n + 1, -1);
    queue<int> q;
    int point = -1, target = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = 1;

            while (!q.empty()) {
                int node = q.front(); q.pop();

                for (auto it : adj[node]) {
                    if (!visited[it]) {
                        visited[it] = 1;
                        parent[it] = node;
                        q.push(it);
                    } else if (parent[node] != it) {
                        point = node;
                        target = it;
                        break;
                    }
                }
                if (point != -1) break;
            }
        }
        if (point != -1) break;
    }

    if (point == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path1, path2;
        int a = point, b = target;

        while (a != -1) {
            path1.push_back(a);
            a = parent[a];
        }
        
        while (b != -1) {
            path2.push_back(b);
            b = parent[b];
        }

        
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());

        int lca = -1;
        int sz = min(path1.size(), path2.size());
        for (int i = 0; i < sz; i++) {
            if (path1[i] == path2[i]) lca = path1[i];
            else break;
        }

        
        vector<int> cycle;
        int x = point;
        while (x != lca) {
            cycle.push_back(x);
            x = parent[x];
        }
        cycle.push_back(lca);

        vector<int> temp;
        x = target;
        while (x != lca) {
            temp.push_back(x);
            x = parent[x];
        }
        reverse(temp.begin(), temp.end());
        for (int v : temp) cycle.push_back(v);

        cycle.push_back(cycle[0]); 

        cout << cycle.size() << endl;
        for (auto v : cycle) cout << v << " ";
        cout << endl;
    }

    return 0;
}
