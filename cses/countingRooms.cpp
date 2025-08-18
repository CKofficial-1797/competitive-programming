#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
void dfs(int x, int y , vector<vector<char>>& grid, vector<vector<int>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    visited[x][y] = 1;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    
    for(int k = 0; k < 4; k++) {
        int nx = x + di[k];
        int ny = y + dj[k];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny, grid, visited);
        }
    }
}

int main() {
    FAST;
    int n,m;
     cin >> n>>m;
     vector<vector<char>> grid(n, vector<char>(m));
     queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '.') {
                q.push({i, j});
            }
        }

    }
    int cnt =0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    while(!q.empty()){
        auto it =q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        if(visited[x][y]) continue;
        dfs(x,y,grid,visited);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}