/*
Determine whether an integer is a palindrome. Do this without extra space.
https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>
#include <math.h>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int i = 0;
        int y = x;
        while (y > 0) {
            y = y/10;
            i++;
        }
        y = x;
        i--;
        while (i > 0 && (int)(y / pow(10, i)) ==  y % 10) {
            y = y - ((int)(y/pow(10, i))) * (int)pow(10, i);
            y = y / 10;
            i=i-2;
        }
        return i <= 0;;
    }
};

TEST(isPalindrome, test) {
    Solution s;
    EXPECT_TRUE(s.isPalindrome(12321));
    EXPECT_TRUE(s.isPalindrome(1221));
    EXPECT_TRUE(s.isPalindrome(2222));
    EXPECT_TRUE(s.isPalindrome(2));
    EXPECT_TRUE(s.isPalindrome(111121111));

    EXPECT_FALSE(s.isPalindrome(1222));
    EXPECT_FALSE(s.isPalindrome(111121121));
}
