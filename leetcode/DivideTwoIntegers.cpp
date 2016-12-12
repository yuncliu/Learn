/*
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 * https://leetcode.com/problems/divide-two-integers/
 */

#include <climits>
#include "gtest/gtest.h"

class Solution {
    public:
        /*
         * beats 13% submissions
         */
        int divide(int dividend, int divisor) {
            if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
                return INT_MAX;
            }
            int sign = (divisor < 0) ^ (dividend < 0) ? -1 : 1;
            int64_t dvd = labs(dividend);
            int64_t dvs = labs(divisor);
            int res = 0;
            while (dvd >= dvs) {
                int64_t temp = dvs, multiple = 1;
                while (dvd >= (temp << 1)) {
                    temp <<= 1;
                    multiple <<= 1;
                }
                dvd -= temp;
                res += multiple;
            }
            return sign > 0 ? res : -res;
        }
        /*
         * exceed time limit
         */
        int divide1(int dividend, int divisor) {
            if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
                return INT_MAX;
            }
            int i = 0;
            int sign = (divisor < 0) ^ (dividend < 0) ? -1 : 1;
            //return dividend/divisor;
            int dvd = abs(dividend);
            int dvi = abs(divisor);
            while ((dvd = (dvd - dvi)) >= 0) {
                i++;
            }
            return sign > 0 ? i : -i;
        }
};

TEST(DivideTwoIntegers, test1) {
    Solution s;
    EXPECT_EQ(s.divide(10,3), 10/3);
}

TEST(DivideTwoIntegers, test2) {
    Solution s;
    EXPECT_EQ(s.divide(100,4), 100/4);
}

TEST(DivideTwoIntegers, test3) {
    Solution s;
    EXPECT_EQ(s.divide(INT_MAX, 4), INT_MAX/4);
    EXPECT_EQ(s.divide(INT_MAX, -1), INT_MAX/-1);
    EXPECT_EQ(s.divide(-2147483648, 1), -2147483648/1);
}
