// #include <bits/stdc++.h>
// using namespace std;

// #define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define endl '\n'

// struct Node {
//     int x, y;
// };

// int main() {
//     FAST;
//     int n, m;
//     cin >> n >> m;

//     vector<vector<char>> grid(n, vector<char>(m));
//     pair<int,int> start, target;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> grid[i][j];
//             if (grid[i][j] == 'A') start = {i, j};
//             if (grid[i][j] == 'B') target = {i, j};
//         }
//     }

//     vector<vector<int>> visited(n, vector<int>(m, 0));
//     vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
//     vector<vector<char>> moveDir(n, vector<char>(m));

//     int di[4] = {-1, 0, 1, 0};
//     int dj[4] = {0, -1, 0, 1};
//     char dirChar[4] = {'U', 'L', 'D', 'R'};

//     queue<Node> q;
//     q.push({start.first, start.second});
//     visited[start.first][start.second] = 1;

//     bool found = false;
//     while (!q.empty()) {
//         auto [x, y] = q.front(); q.pop();
//         if (make_pair(x,y) == target) {
//             found = true;
//             break;
//         }
//         for (int k = 0; k < 4; k++) {
//             int nx = x + di[k], ny = y + dj[k];
//             if (nx >= 0 && nx < n && ny >= 0 && ny < m 
//                 && !visited[nx][ny] && grid[nx][ny] != '#') {
//                 visited[nx][ny] = 1;
//                 parent[nx][ny] = {x,y};
//                 moveDir[nx][ny] = dirChar[k];
//                 q.push({nx, ny});
//             }
//         }
//     }

//     if (!found) {
//         cout << "NO" << endl;
//     } else {
//         cout << "YES" << endl;
//         string path;
//         auto [x,y] = target;
//         while (make_pair(x,y) != start) {
//             path.push_back(moveDir[x][y]);
//             auto [px, py] = parent[x][y];
//             x = px; y = py;
//         }
//         reverse(path.begin(), path.end());
//         cout << path.size() << endl;
//         cout << path << endl;
//     }

//     return 0;
// }
