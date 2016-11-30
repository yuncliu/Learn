/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

https://leetcode.com/problems/regular-expression-matching/
*/
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

TEST(RegularExpressionMatching, test) {
    Solution s;
    EXPECT_FALSE(s.isMatch("aaa","aa"));
    EXPECT_FALSE(s.isMatch("aaa","aa")); // false
    EXPECT_FALSE(s.isMatch("aa", "a"));
    EXPECT_TRUE(s.isMatch("aa", "aa"));
    EXPECT_TRUE(s.isMatch("aa", "a*"));
    EXPECT_TRUE(s.isMatch("aaa", "a*"));
    EXPECT_TRUE(s.isMatch("aab", "c*a*b"));
    EXPECT_TRUE(s.isMatch("aa", ".*"));
    EXPECT_TRUE(s.isMatch("ab", ".*"));
}
