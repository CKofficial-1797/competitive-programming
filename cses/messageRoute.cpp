#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int n,m;
     cin >> n>>m;
     vector<vector<int>>adj(n+1);
     while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
    vector<int>visited(n+1,0);
    queue<int>q;
    vector<int>parent(n+1,-1);
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        auto node =q.front(); q.pop();
        // if(visited[node])continue;
        
        for(auto it :adj[node]){
             
            if(!visited[it]){
                parent[it]=node;
                if(it==n){
                vector<int>temp;
                temp.push_back(it);
                while(parent[it]!=-1){
                    temp.push_back(parent[it]);
                    it =parent[it];
                }
                cout<<temp.size()<<endl;
                reverse(temp.begin(),temp.end());
                for(auto el :temp){
                    cout<<el<<" ";
                }
                return 0;
                }
               visited[it]=1;
                q.push(it);
                
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    
    return 0;
}