#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAdd(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1));

        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        for (int r = 0; r <= n; r++)
            for (int c = 1; c <= n; c++)
                diff[r][c] += diff[r][c - 1];

        for (int r = 1; r <= n; r++)
            for (int c = 0; c <= n; c++)
                diff[r][c] += diff[r - 1][c];

        vector<vector<int>> res(n, vector<int>(n));
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                res[r][c] = diff[r][c];

        return res;
    }
};
