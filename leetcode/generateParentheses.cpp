/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
   "((()))",
   "(()())",
   "(())()",
   "()(())",
   "()()()"
 ]
 */
#include <vector>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

class Solution {
    public:
    vector<string> generateParentheses(int n) {
        vector<string> r;
        /*
         * At first, no ( is in the string, so must no ).
         * Here means, currently the string has nothing, we can insert 3 ( but no ),
         */
        recursive(r, "", n, 0);
        return r;
    }

    void recursive(vector<string>& r, string s,int left, int right){
        if (!left && !right) {
            r.push_back(s);
            return;
        }
        // check and insert )
        if (right > 0) {
            // ) not impact the (
            recursive(r, s + ")", left, right - 1);
        }
        // check and insert (
        if (left > 0) {
            /* only when one ( is inserted then a ) can be inserted.
             * Count of ( minused 1 means one ( is inserted, then a ) can be
             * insert, so count of ) add 1
             */
            recursive(r, s + "(", left - 1, right + 1);
        }
        /*
         * the order of these two "if" does not influence the result.
         */
    }
};

TEST(generateParentheses, test1) {
    Solution s;
    vector<string> result = s.generateParentheses(3);
    cout << "[" << endl;
    for (auto i : result ){
        cout << i << endl;
    }
    cout << "]" << endl;
    EXPECT_EQ(result.size(), (size_t)5);
}

TEST(generateParentheses, test2) {
    Solution s;
    vector<string> result = s.generateParentheses(4);
    cout << "[" << endl;
    for (auto i : result ){
        cout << i << endl;
    }
    cout << "]" << endl;
}
