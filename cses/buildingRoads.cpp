#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

void dfs(int i ,vector<vector<int>>&adj,vector<int>&visited,vector<int>&parent){
    visited[i]=1;
    for(auto it :adj[i]){
        if(!visited[it]){
            parent[it]=i;
            dfs(it,adj,visited,parent);
        }
    }
}

int main() {
    FAST;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n+1, 0);
    vector<int>parent(n+1,-1);
    int cnt =0;
    for(int i =1;i<=n;i++){
        
        if(!visited[i]){
            cnt++;
            dfs(i,adj,visited,parent);
        }
    }
    
    cout<<cnt-1<<endl;
    if(cnt==1) return 0;
    int first ;
    bool flag =true;
    for(int i =1 ;i<=n;i++){
        if(parent[i]==-1){
            if(!flag){
                cout<<first<<" "<<i<<endl;
                first=i;
               
            }else{
                first=i;
                flag =false;
            }
        }
    }
    return 0;
}