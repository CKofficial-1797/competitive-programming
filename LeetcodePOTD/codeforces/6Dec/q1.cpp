#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int MOD = 1e9 + 7;

int main() {
    FAST;
    int t;
     cin >> t;
    while (t--) {
        int n ;
        cin>>n;
        vector<int>color(n);
        unordered_set<int>st;
        for(int i =0 ;i<n ;i++){
            cin>>color[i];
            st.insert(color[i]);
        }
        int distinct =st.size();
        sort(color.begin(),color.end());
        auto it = lower_bound(color.begin(),color.end(),distinct);
        cout<< *it<< endl;

    }
    return 0;
}