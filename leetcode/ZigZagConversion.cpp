/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

https://leetcode.com/problems/zigzag-conversion/
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            vector<string> lines;
            for (int i = 0; i < numRows; ++i) {
                lines.push_back("");
            }
            int j = 0;
            bool flag = true;
            for (int i = 0; i < s.length(); ++i) {
                lines[j] = lines[j] + s[i];

                if (j == 0) {
                    flag = true;
                }
                else if (j == numRows - 1) {
                    flag = false;
                }

                if (flag == true && j + 1< numRows) {
                        j++;
                } else if (j - 1 >=0){
                    j--;
                }
            }
            stringstream sm;
            for (int i = 0; i < numRows; ++i) {
                sm << lines[i];
            }
            return sm.str();
        }
};


void test() {
    Solution s;
    //cout << "PAYPALISHIRING 3   :"<< s.convert("PAYPALISHIRING", 3) << endl;
    cout << "AB 1   :"<< s.convert("AB", 1) << endl;
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
