#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long ts = totalSum(n);
        long long diff = ts - target;

        if (!isValidDiff(diff)) return {};

        long long rem = diff / 2;
        if (rem > ts) return {};

        vector<int> ans;
        ans.reserve(n);

        fillAnswer(n, rem, ans);

        if (rem > 0) return {};

        finalizeAnswer(ans);
        return ans;
    }

private:
    long long totalSum(int n) {
        return 1LL * n * (n + 1) / 2;
    }

    bool isValidDiff(long long diff) {
        return diff >= 0 && (diff % 2 == 0);
    }

    void fillAnswer(int n, long long &rem, vector<int> &out) {
        for (int i = n; i >= 1; --i) {
            if (rem >= i) {
                out.push_back(-i);
                rem -= i;
            } else {
                out.push_back(i);
            }
        }
    }

    void finalizeAnswer(vector<int> &out) {
        sort(out.begin(), out.end());
    }
};
