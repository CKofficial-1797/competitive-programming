#include <string>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        string digits = to_string(n);
        long long xValue = buildNumber(digits);
        long long sValue = digitSum(digits);
        return xValue * sValue;
    }

private:
    long long buildNumber(const string &digits) {
        long long result = 0;
        for (char ch : digits) {
            if (ch != '0') {
                result = result * 10 + (ch - '0');
            }
        }
        return result;
    }

    long long digitSum(const string &digits) {
        long long total = 0;
        for (char ch : digits) {
            if (ch != '0') {
                total += (ch - '0');
            }
        }
        return total;
    }
};
