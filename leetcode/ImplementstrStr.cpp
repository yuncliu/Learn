/*
 * Implement strStr().
 *
 * Returns the index of the first occurrence of
 * needle in haystack, or -1 if needle is not part of haystack.
 */
#include <string>
#include "gtest/gtest.h"
#include "ListNode.h"
using namespace std;

class Solution {
    public:
        /*
         * try kmp
         * beats 12% submissions. - -
         */
        int strStr(string haystack, string needle) {
            if (needle.empty()) {
                return 0;
            }
            vector<int> next = buildNextTable(needle);
            for (string::size_type i = 0, j = 0; i < haystack.length(); ) {
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                }
                if (j == needle.length()) {
                    return i - j;
                }
                if (i < haystack.length() && haystack[i] != needle[j]) {
                    if (j){
                        j = next[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            return -1;
        }

        vector<int> buildNextTable(string& needle) {
            vector<int> next(needle.length(), 0);
            for (string::size_type i = 1, len = 0; i < needle.length(); ) {
                if (needle[i] == needle[len])
                    next[i++] = ++len;
                else if (len) {
                    len = next[len - 1];
                }
                else {
                    next[i++] = 0;
                }
            }
            return next;
        }
        /*
         * beats 57% submissions. suprised me, this is
         * just a violence matching.
         * directly * return haystack.find(needle);  also beats 57% submissions
         */
        int strStr57(string haystack, string needle) {
            if (haystack.size() < needle.size()) {
                return -1;
            }
            if (needle.size() == 0) {
                return 0;
            }

            for (string::size_type i = 0; i < haystack.size() - needle.size() + 1; ++i) {
                string::size_type pos = 0;
                while(haystack[i + pos] == needle[pos] && pos < needle.size()) {
                    pos++;
                }
                if (pos == needle.size()) {
                    return i;
                }
            }
            return -1;//haystack.find(needle);
        }
};

TEST(ImplementstrStr, test1) {
    Solution s;
    string a = "abcdefghijklmnopqrstuvwxyz";
    string b = "rst";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}

TEST(ImplementstrStr, test2) {
    Solution s;
    string a = "abcdefghijklmnopqrstuvwxyz";
    string b = "tsr";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}

TEST(ImplementstrStr, test3) {
    Solution s;
    string a = "";
    string b = "a";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}

TEST(ImplementstrStr, test4) {
    Solution s;
    string a = "";
    string b = "";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}

TEST(ImplementstrStr, test5) {
    Solution s;
    string a = "a";
    string b = "a";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}

TEST(ImplementstrStr, test6) {
    Solution s;
    string ss = "abcabcacab";
    vector<int> next = s.buildNextTable(ss);
    for (auto it : next) {
        cout << it <<" , ";
    }
    cout << endl;
}

TEST(ImplementstrStr, test7) {
    Solution s;
    string a = "mississippi";
    string b = "a";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}
