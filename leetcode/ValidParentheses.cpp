/*
parentheses   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 152325
Total Submissions: 479907
Difficulty: Easy
Contributors: Admin
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/
#include <string>
#include <iostream>
#include <stack>
#include "gtest/gtest.h"
using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        stack<char> stack;
        for (size_t i = 0; i < s.size(); ++i) {
            if (stack.empty()) {
                stack.push(s[i]);
            }
            else {
                int x = stack.top() - s[i];
                if (x != 0 && x >= -2 && x <= 2) {
                    stack.pop();
                } else {
                    stack.push(s[i]);
                }
            }
        }
        return stack.empty();
    }
};

TEST(ValidParentheses, test1) {
    Solution s;
    EXPECT_TRUE(s.isValid("()"));
    EXPECT_TRUE(s.isValid("[]"));
    EXPECT_TRUE(s.isValid("{}"));
}

TEST(ValidParentheses, test2) {
    Solution s;
    EXPECT_FALSE(s.isValid("(]"));
    EXPECT_FALSE(s.isValid("([)]"));
}

TEST(ValidParentheses, test3) {
    Solution s;
    EXPECT_TRUE(s.isValid("{[]}"));
    EXPECT_TRUE(s.isValid("{[()]}"));
}
