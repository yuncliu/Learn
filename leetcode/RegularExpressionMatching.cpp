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

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
    bool match(const char* s, const char* p) {
        if (p[0] == '\0') {
            return true;
        }
        if (p[0] == '.') {
            return this->match(&s[1], &p[1]);
        }
        if (p[0] == s[0] && s[0] != '\n') {
            return this->match(&s[1], &p[1]);
        }
        return false;
    }
};

void test(string str, string regular) {
    Solution s;
    cout << "[" << str << "] match [" << regular << "] = [" << (s.isMatch(str, regular) ? "ture]" : "false]") << endl;
}

int main(int argc, char *argv[]) {
    test("abc", "a");
    test("abc", "d");
    test("abc", "a.c");
    test("abc", "ab.");
    return 0;
}
