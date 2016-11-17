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

void test(string str, string regular, bool expected) {
    Solution s;
    cout << "[" << str << "] match [" << regular << "] = [" << (s.isMatch(str, regular) ? "ture]" : "false]");
    cout << " expected [" << (expected ? "true]" : "false]") << endl;
}

int main(int argc, char *argv[]) {
    test("aaa","aa", false); // false
    test("aa", "a*", true);//true
    test("aa","a", false); //false
    test("aa","aa", true); //true
    test("aaa", "a*", true);//true
    test("aab", "c*a*b", true);//true
    test("aa", ".*", true); // true
    test("ab", ".*", true); // true
    test("aab", "c*a*b", true); // → true
    test("aaa", "ab*ac*a", true);
    /*
    */
    return 0;
}
