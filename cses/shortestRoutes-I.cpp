#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
struct node {
    // int curr;
    int next;
    ll weight;
};

int main() {
    FAST;
    int n, m;
    cin >> n >> m;
    vector<vector<node>>adj(n+1);
    // vector<int>visited(n+1,0);
    while (m--) {
        int u , v;
        ll wt;
        cin>>u >>v>>wt;
        adj[u].push_back({v,wt});
        // adj[v].push_back({u,wt});
    }
   priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
   vector<ll>mindist(n+1,LLONG_MAX);
   mindist[1]=0;
    pq.push({0,1});
    // visited[1]=1;
    while(!pq.empty()){
        auto it =pq.top();
        pq.pop();
        ll dist =it.first;
        int city =it.second;
        if (dist > mindist[city]) continue;
        for(auto &it : adj[city]){
                

                // visited[it.next]=1;
                if(mindist[it.next]>dist+it.weight){
                mindist[it.next]=dist+it.weight;
                pq.push({mindist[it.next],it.next});
                }
           
        }
        
    };
    for (int i = 1; i <= n; i++) {
        cout << mindist[i] << " ";
    }
    cout << "\n";
    return 0;
}