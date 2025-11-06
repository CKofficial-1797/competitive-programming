#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'


const int MOD = 1e9 + 7;
vector<vector<int>>adj(2e5+1);
vector<long long>subtree_size,sumfromNode(2e5+1,0);

void dfs1(int n , int parent,long long depth){   
    sumfromNode[1]+=depth;
    subtree_size[n]=1;
    for(auto it :adj[n]){
        if(it==parent) continue;
       
        dfs1(it,n,depth+1);
        subtree_size[n]+=subtree_size[it];
    }
  
}
void dfs2(int n , int parent,int t ){
    for(auto it : adj[n]){
        if(it==parent) continue;
        sumfromNode[it] =sumfromNode[n]+t- 2*subtree_size[it];
        dfs2(it,n,t);
    }
}



int main() {
    FAST;
    int t;
     cin >> t;
     adj.assign(t+1,{});
     subtree_size.assign(t+1,0);
     sumfromNode.assign(t+1,0);
     
    for(int i =1; i<=t-1;i++){
        int u , v;
        cin>>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,-1,0);
    dfs2(1,-1,t);
    for(int i =1; i<=t ;i++){
        cout<<sumfromNode[i]<<" ";
    }
    
    
    return 0;
}