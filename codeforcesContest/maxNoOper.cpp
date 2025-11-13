#include <string>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        long long onesSeen = 0;
        long long result = 0;
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (s[i] == '1') {
                ++onesSeen;
                ++i;
            } else {
                result += onesSeen;
                while (i < n && s[i] == '0') ++i;
            }
        }

        return result;
    }
};
