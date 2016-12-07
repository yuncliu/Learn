/*
5. Longest Palindromic Substring   QuestionEditorial Solution  My Submissions
Total Accepted: 147281
Total Submissions: 613340
Difficulty: Medium
Contributors: Admin
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

https://leetcode.com/problems/longest-palindromic-substring/

*/

#include <iostream>
#include <string>
#include <sstream>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    // time exipred
    string longestPalindrome_1(string s) {
        string palin;
        for (string::size_type start = 0; start < s.length(); ++start) {
            for (string::size_type end = start; end < s.length(); ++end) {
                int i = start;
                int j = end;
                // judge if substring between start and i is palindromic
                while(s[i] == s[j] && i < j) {
                    i++;
                    j--;
                }
                if (i >= j) {
                    string tmp = s.substr(start, end - start + 1);
                    palin = palin.length() > tmp.length() ? palin : tmp;
                }
            }
        }
        return palin;
    }

    string longestPalindrome(string s) {
        string max(s.substr(0, 1));
        for (string::size_type i = 0; i < s.length() - 1; ++i) {
            string odd = check(s, i, i);
            max = max.length() > odd.length() ? max : odd;
            string even = check(s, i, i + 1);
            max = max.length() > even.length() ? max : even;
        }
        return max;
    }

    string check(string s, string::size_type left, string::size_type right) {
        while(s[left] == s[right] && right < s.length()) {
            left--;
            right++;
        }
        //cout <<"[" << left <<", "<< right << "] " << s.substr(left + 1, right - left - 1)<<endl;;
        return s.substr(left + 1, right - left - 1);
    }
};

TEST(LongestPalindromicSubstring, test) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("bb"), "bb");
    EXPECT_EQ(s.longestPalindrome("babad"), "aba");
    EXPECT_EQ(s.longestPalindrome("aba"), "aba");
    EXPECT_EQ(s.longestPalindrome("abba"), "abba");
    EXPECT_EQ(s.longestPalindrome("a"), "a");
    EXPECT_EQ(s.longestPalindrome("abccba"), "abccba");
    EXPECT_EQ(s.longestPalindrome("abcdeffeda"), "deffed");
}
