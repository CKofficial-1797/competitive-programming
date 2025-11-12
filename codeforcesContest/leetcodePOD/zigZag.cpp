#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        vector<string> rows(min(numRows, (int)s.size()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (auto& row : rows) result += row;
        return result;
    }
};

int main() {
    string s;
    int numRows;
    cin >> s >> numRows;
    Solution sol;
    cout << sol.convert(s, numRows) << '\n';
    return 0;
}
