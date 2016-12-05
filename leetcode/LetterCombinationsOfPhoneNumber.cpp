/*
 Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

https://leetcode.com/problems/letter-combinations-of-a-phone-number/

*/

#include <vector>
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

class Solution {
    public:
    vector<string> letterCombinations(string digits) {
        //                         0   1    2
        vector<string> numbers = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;

        for (size_t i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            vector<string> tmp;
            if (num >= 2 && num <= 9) {
                for (size_t j = 0; j < numbers[num].size(); ++j) {
                    if (result.empty()) {
                        tmp.push_back(numbers[num].substr(j, 1));
                    }
                    else {
                        for (size_t k = 0; k < result.size(); ++k) {
                            tmp.push_back(result[k] + numbers[num].substr(j, 1));
                        }
                    }
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};

TEST(LetterCombinations, test1) {
    Solution s;
    vector<string> r = s.letterCombinations("23");
    EXPECT_EQ(r.size(), (size_t)9);
    for (auto i : r) {
        cout <<i<<endl;
    }
}

TEST(LetterCombinations, test2) {
    Solution s;
    vector<string> r = s.letterCombinations("234");
    EXPECT_EQ(r.size(), (size_t)27);
    for (auto i : r) {
        cout <<i<<endl;
    }
}
