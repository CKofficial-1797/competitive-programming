#include <iostream>
#include <vector>
using namespace std;

static inline void flushln() { cout << endl; cout.flush(); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int,int>> ranges(q);
        for (int i = 0; i < q; ++i) {
            int l, r; 
            cin >> l >> r;
            ranges[i] = {l, r};
        }

        int bestMex = 0;
        for (int i = 0; i < q; ++i) {
            int l = ranges[i].first, r = ranges[i].second;
            cout << "? " << l << ' ' << r;
            flushln();                 
            int mexReply;
            if (!(cin >> mexReply)) return 0;
            if (mexReply > bestMex) bestMex = mexReply;
        }

        cout << "! " << bestMex;
        flushln();                      
    }
    return 0;
}
