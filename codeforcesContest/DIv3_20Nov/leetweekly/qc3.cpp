#include <bits/stdc++.h>
using namespace std;


long long get_dist(long long coord, long long range) {
    long long val = abs(coord);
    if (val <= range) return 0;
    return val - range;
}

bool check_reach(long long tx, long long ty, int moves4, int moves8) {
    
    long long gapX = get_dist(tx, moves8);
    long long gapY = get_dist(ty, moves8);
    
    return (gapX + gapY) <= moves4;
}

void run_case() {
    int len;
    long long reqX, reqY;
    cin >> len >> reqX >> reqY;
    
    string seq;
    cin >> seq;

    int type4 = 0;
    int type8 = 0;

    for (int i = 0; i < len; i++) {
        if (seq[i] == '4') type4++;
        else type8++;
    }

    if (check_reach(reqX, reqY, type4, type8)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    while (cases--) {
        run_case();
    }
    return 0;
}