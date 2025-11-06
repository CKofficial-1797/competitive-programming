#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
vector<vector<int>>adj(2e5+1);
// vector<int>visited(2e5+1,0);
// vector<int>parentU(2e5+1,-1);

pair<int,int> dfs(int node,int parent){
    pair<int,int>best ={0,node};
    for(auto it :adj[node]){
        if(it==parent)continue;
        auto next =dfs(it,node);
        next.first++;
        if(next.first>best.first)  best=next;    
    }
    return best;
}

int main() {
    FAST;
    int t;
     cin >> t;
     adj.assign(t+1,{});
     
    for(int i =1; i<=t-1;i++){
        int u , v;
        cin>>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    auto A =dfs(1,-1);
    auto B =dfs(A.second,-1);
    cout<<B.first<<endl;
    return 0;
}