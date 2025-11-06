#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

pair<int,int>dfs(int n ,int p,vector<int>&dist){
    pair<int,int>best ={dist[n],n};
    for(auto it :adj[n]){
        if(it==p)continue;
        dist[it]=dist[n]+1;
        auto next =dfs(it,n,dist);
        
        if(next.first>best.first) best=next;
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
    // to get distance of all from  A
    vector<int>distA(t+1,0);
    auto A = dfs(1,-1,distA);
    
    vector<int>distB(t+1,0);
    auto B =dfs(A.second,-1,distB);

    vector<int>distC(t+1,0);
    dfs(B.second,-1,distC);

    for(int i =1;i<=t ;i++){
        cout<<max(distB[i],distC[i])<<" ";
    }

    return 0;
}