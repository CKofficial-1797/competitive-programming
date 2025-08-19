#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

struct Node {
    int r, c;
};

int main() {
    FAST;
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> monsterTime(n, vector<int>(m, INT_MAX));
    vector<vector<int>> playerTime(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

    queue<Node> q;

    Node start;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterTime[i][j] = 0;
                q.push({i, j});
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

 
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    char moveChar[4] = {'D', 'U', 'R', 'L'};

    
    while (!q.empty()) {
        Node node = q.front(); q.pop();
        int r = node.r, c = node.c;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (grid[nr][nc] != '#' && monsterTime[nr][nc] > monsterTime[r][c] + 1) {
                    monsterTime[nr][nc] = monsterTime[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    
    queue<Node> pq;
    pq.push(start);
    playerTime[start.r][start.c] = 0;

    Node escape = {-1, -1};
    while (!pq.empty()) {
        Node node = pq.front(); pq.pop();
        int r = node.r, c = node.c;

        
        if (r == 0 || r == n-1 || c == 0 || c == m-1) {
            escape = {r, c};
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (grid[nr][nc] != '#' && playerTime[nr][nc] == -1) {
                    int nextTime = playerTime[r][c] + 1;
                    if (nextTime < monsterTime[nr][nc]) { 
                        playerTime[nr][nc] = nextTime;
                        parent[nr][nc] = {r, c};
                        pq.push({nr, nc});
                    }
                }
            }
        }
    }

    if (escape.r == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        string path;
        Node cur = escape;
        while (!(cur.r == start.r && cur.c == start.c)) {
            int pr = parent[cur.r][cur.c].first;
            int pc = parent[cur.r][cur.c].second;
            for (int k = 0; k < 4; k++) {
                if (pr + dr[k] == cur.r && pc + dc[k] == cur.c) {
                    path.push_back(moveChar[k]);
                }
            }
            cur = {pr, pc};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }

    return 0;
}
