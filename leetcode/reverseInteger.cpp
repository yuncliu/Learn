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
#include "gtest/gtest.h"

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
            for (size_t i = 0; i < v.size(); ++i) {
                long base = 1;
                for (size_t j = 0; j < v.size() - i - 1; ++j) {
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

TEST( reverseInteger, test) {
    Solution s;
    EXPECT_EQ(s.reverse(123), 321);
    EXPECT_EQ(s.reverse(0), 0);
    EXPECT_EQ(s.reverse(10), 1);
    EXPECT_EQ(s.reverse(-123), -321);
}
