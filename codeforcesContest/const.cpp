#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        string s;
        cin >> s;
        int n = (int)s.size();

        
        bool infinite = false;
        for (int i = 0; i + 1 < n; ++i) {
            bool leftHasRightEdge = (s[i] == '>' || s[i] == '*');
            bool rightHasLeftEdge = (s[i+1] == '<' || s[i+1] == '*');
            if (leftHasRightEdge && rightHasLeftEdge) {
                infinite = true;
                break;
            }
        }
        if (infinite) {
            cout << -1 << '\n';
            continue;
        }


        int firstRight = n;   
        int lastLeft = -1;    
        for (int i = 0; i < n; ++i) {
            if (s[i] == '>') firstRight = min(firstRight, i);
            if (s[i] == '<') lastLeft = max(lastLeft, i);
        }

        
        if (firstRight == n && lastLeft == -1) {
            cout << 1 << '\n';
            continue;
        }

        
        if (firstRight == n || lastLeft == -1) {
            cout << n << '\n';
            continue;
        }

        //if both exists 

        
        int ans = n-firstRight+1;
        
        cout << ans + 1 << '\n';
    }

    return 0;
}
