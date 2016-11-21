/*
ven an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
https://leetcode.com/problems/integer-to-roman/
*/

#include <iostream>
#include <sstream>
#include <map>

using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            if (num < 1 || num > 3999) {
                return "";
            }
            map<int, string> m;
            m.insert(pair<int, string>(1000, "M"));
            m.insert(pair<int, string>(900, "CM"));
            m.insert(pair<int, string>(500, "D"));
            m.insert(pair<int, string>(400, "CD"));
            m.insert(pair<int, string>(100, "C"));
            m.insert(pair<int, string>(90, "XC"));
            m.insert(pair<int, string>(50, "L"));
            m.insert(pair<int, string>(40, "XL"));
            m.insert(pair<int, string>(10, "X"));
            m.insert(pair<int, string>(9, "IX"));
            m.insert(pair<int, string>(5, "V"));
            m.insert(pair<int, string>(4, "IV"));
            m.insert(pair<int, string>(1, "I"));
            stringstream sm;
            for (map<int, string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it) {
                int times = num / it->first;
                num = num % it->first;
                for (int i = 0; i < times; ++i) {
                    sm << it->second;
                }
            }
            return sm.str();
        }

        /*
         * another method, find in discussions.
         */
        string intToRoman2(int num) {
            char* str[4][10] = {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}
            };
            //string val;
            stringstream val;
            val << str[3][num / 1000 % 10];
            val << str[2][num / 100  % 10];
            val << str[1][num / 10   % 10];
            val << str[0][num        % 10];
            return val.str();
        }
};

void test(int num) {
    Solution s;
    cout << "[" << num <<"] Roman = [" << s.intToRoman(num) << "]" << endl;
    cout << "[" << num <<"] Roman = [" << s.intToRoman2(num) << "]" << endl;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < 99; ++i) {
        test(i);
    }
    test(9);
    return 0;
}
