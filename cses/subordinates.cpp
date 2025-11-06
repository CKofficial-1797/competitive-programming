#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int t;
     cin >> t;
     vector<vector<int>>adj(t+1);
     int first ,second;
   for(int i =0 ;i<t-1 ;i++){
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);     
        
   }
   int cnt=0;
   vector<int>visited(t+1,0);
//    vector<int>paired(t+1,-1);
    for(int i =1 ;i<=t;i++){
        // bool flag =false;
        if(visited[i])continue;
        for(auto it: adj[i]){
            sort(adj[it].begin(), adj[it].end(), [&adj](int i, int j) {
                return adj[i].size() <= adj[j].size();
            });
            if( !visited[it]){
                visited[it]=1;
                visited[i]=1;
                cnt++;
                // paired[i]=it,
                // paired[it]=i;
                // flag =true;
                break;
            }

        }
    }
     cnt =count(visited.begin(),visited.end(),1);
     cout<<cnt/2<<endl;
}