#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;
const int MAX =2e5+5;
int up[MAX][20];
vector<vector<int>>adj(MAX);

int main() {
    FAST;   
    int n ,q;
    cin>>n>>q;
    up[1][0]=-1;
    for(int i =2 ;i<=n;i++){
        cin>>up[i][0];
    }
    for(int j =1 ;j<20 ;j++){
         for(int i =1 ;i<=n ;i++){
            if(up[i][j-1]!=-1){
                up[i][j] =up[up[i][j-1]][j-1];
            }else{
                up[i][j]=-1;
            }
        }
    }

    while(q--){
        int node ,k;
        cin>> node>>k;
        for(int j =0;j<20;j++){
            if(k& (1<<j)){
                node=up[node][j];
                if(node==-1)break;
            }
        }
        cout<<node<<endl;
    }
   
    return 0;
}