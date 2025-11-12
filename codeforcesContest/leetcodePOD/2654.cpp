#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;

        int shortestLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int currentGcd = nums[i];
            if (currentGcd == 1) { shortestLen = 1; break; }
            for (int j = i + 1; j < n; ++j) {
                currentGcd = gcd(currentGcd, nums[j]);
                if (currentGcd == 1) {
                    shortestLen = min(shortestLen, j - i + 1);
                    break;
                }
            }
        }

        if (shortestLen == INT_MAX) return -1;
        return (shortestLen - 1) + (n - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    Solution sol;
    cout << sol.minOperations(nums) << '\n';
    return 0;
}
