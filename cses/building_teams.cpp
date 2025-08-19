#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int n ,m ;
     cin >> n>>m;
     vector<vector<int>>adj(n+1);
     vector<int>visited(n+1,0);
     vector<int>whichTeam(n,-1);
     while(m--){
        int u , v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     for(int i =1;i<=n;i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i]=1;
            whichTeam[i-1]=1;
            while(!q.empty()){
            auto node =q.front();

            q.pop();
            for(auto it :adj[node]){
                if(!visited[it]){
                    if(whichTeam[node-1]==1){
                         whichTeam[it-1]=2;
                    }
                    else {
                         whichTeam[it-1]=1;
                    }
                    visited[it]=1;
                    q.push(it);

                }else{
                    if(whichTeam[node-1]==whichTeam[it-1]){
                        cout<<"IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
        }
     }
     for (auto e :whichTeam){
        cout<<e<<" ";
     }

     
    
    return 0;
}