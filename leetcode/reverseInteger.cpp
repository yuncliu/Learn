/*
7. Reverse Integer   QuestionEditorial Solution  My Submissions
Total Accepted: 184382
Total Submissions: 778073
Difficulty: Easy
Contributors: Admin
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

https://leetcode.com/problems/reverse-integer/
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            vector<int> v;
            while(x != 0) {
                int a = x % 10;
                x = x / 10;
                v.push_back(a);
            }
            int reversed = 0;
            long reverse_long = 0;
            for (int i = 0; i < v.size(); ++i) {
                long base = 1;
                for (int j = 0; j < v.size() - i - 1; ++j) {
                    base *= 10;
                }
                reversed += base * v[i];
                reverse_long += base * v[i];
                if (reversed != reverse_long) {
                    // overflow occured;
                    return 0;
                }
            }
            return reversed;
        }
};


void test(int x) {
    Solution s;
    cout << x  <<":"<< s.reverse(x) << endl;
}

int main(int argc, char *argv[]) {
    /*
    test(123);
    test(0);
    test(10);
    test(01);
    test(-123);
    test(1534236469);
    */
    test(1);
    return 0;
}
