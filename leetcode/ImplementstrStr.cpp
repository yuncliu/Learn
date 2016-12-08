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
         */
        int strStr(string haystack, string needle) {
            if (haystack.size() < needle.size()) {
                return -1;
            }
            if (needle.size() == 0) {
                return 0;
            }
            vector<int> next = build_next(needle);

            string::size_type pos = 0;
            for (string::size_type i = 0; i < haystack.size() - needle.size() + 1; ++i) {
                while(haystack[i + pos] == needle[pos] && pos < needle.size()) {
                    pos++;
                }
                if (pos == needle.size()) {
                    return i;
                } else {
                    pos = next[pos-1] + 1;
                }
            }
            return -1;//haystack.find(needle);
        }
        /*
         *
         */
        vector<int> build_next(string str) {
            vector<int> next(str.size());
            int i, j;
            next[0] = -1;
            for( i = 1; i < (int)str.size(); i++ ) {
                j = next[ i - 1 ];
                while( str[ j + 1 ] != str[ i ] && ( j >= 0 ) ) {
                    j = next[ j ];
                }
                if( str[ i ] == str[ j + 1 ] ) {
                    next[ i ] = j + 1;
                } else {
                    next[ i ] = -1;
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
    vector<int> next = s.build_next(ss);
    for (auto it : next) {
        cout << it <<" , ";
    }
    cout << endl;
    //ListNode::printContainer(next);
}

TEST(ImplementstrStr, test7) {
    Solution s;
    string a = "mississippi";
    string b = "a";
    EXPECT_EQ(s.strStr(a, b), (ssize_t)a.find(b));
}
