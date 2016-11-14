/*
 https://leetcode.com/problems/string-to-integer-atoi/
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h> // for INT_MAX and INT_MIN

using namespace std;

class Solution {
    public:
        int myAtoi(string str) {
            int pos = str.find_first_not_of(' ') // very useful function;
            long result = 0;
            int indicator = 1;
            if ( str[pos] == '+' || str[pos] == '-' ) {
                indicator = str[pos] == '+' ? 1 : -1;
                pos++;
            }
            while ( str[pos] >= '0' && str[pos] <= '9' ) {
                result = result * 10 + (str[pos] - '0');
                //str = str.substr(1, str.length() - 1);
                if (indicator * result > INT_MAX) {
                    return INT_MAX;
                }
                if (indicator * result < INT_MIN) {
                    return INT_MIN;
                }
                pos++;
            }
            return (int)(indicator * result);
        }
};


void test(string str) {
    Solution s;
    cout << str  <<":"<< s.myAtoi(str) << endl;
}

int main(int argc, char *argv[]) {
    test("123");
    test("+-2"); // this need to conside
    test("-1"); // this need to conside
    test("+123");
    test("0");
    test("10");
    test("01");
    test("010");
    test("   010");
    test("-123");
    test("9534236469");
    test("12c1");
    test("-12c1");
    test("-2147483648");
    test("2147483648"); // this expected 2147483647
    return 0;
}
