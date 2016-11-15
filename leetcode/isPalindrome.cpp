/*
Determine whether an integer is a palindrome. Do this without extra space.
https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int i = 0;
        int y = x;
        while (y > 0) {
            y = y/10;
            i++;
        }
        y = x;
        i--;
        while (i > 0 && (int)(y / pow(10, i)) ==  y % 10) {
            y = y - ((int)(y/pow(10, i))) * (int)pow(10, i);
            y = y / 10;
            i=i-2;
        }
        return i <= 0;;
    }
};

void test(int x) {
    Solution s;
    cout << "[" << x << "] : [" << s.isPalindrome(x) << "]" << endl;
}

int main(int argc, char *argv[]) {
    test(12321);
    test(1221);
    test(1222);
    test(2222);
    test(2);
    test(111121111);
    test(111121121);
    return 0;
}
