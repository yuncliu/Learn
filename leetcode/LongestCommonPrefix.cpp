#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int pos = 0;
        while(check_equal(strs, pos)) {
            pos++;
        }
        return strs[0].substr(0, pos);
    }

    bool check_equal(vector<string>& strs, size_t pos) {
        char t = strs[0][pos];
        if (t == '\0') {
            return false;
        }
        for (auto it = strs.begin(); it != strs.end(); ++it) {
            if ((*it)[pos] != t) {
                return false;
            }
        }
        return true;
    }
};

TEST(LongestCommonPrefix, test1) {
    Solution s;
    vector<string> strs;
    strs.push_back("abcdeft");
    strs.push_back("abceeft");
    strs.push_back("abckeft");
    EXPECT_EQ(s.longestCommonPrefix(strs), "abc");
}

TEST(LongestCommonPrefix, test2) {
    Solution s;
    vector<string> strs;
    strs.push_back("");
    EXPECT_EQ(s.longestCommonPrefix(strs), "");
}
