/*

Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container,
such that the container contains the most water.

Note: You may not slant the container.

https://leetcode.com/problems/container-with-most-water/
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        /*time limit
        int maxArea(vector<int>& height) {
            int result = 0;
            for (int i = 0; i < height.size(); ++i) {
                for (int j = i; j < height.size(); ++j) {
                    int area = (j-i) * (height[i] < height[j] ? height[i] : height[j]);
                    result = result > area ? result : area;
                }
            }
            return result;
        }
        */
        int maxArea(vector<int>& height) {
            int result = 0;
            int i = 0;
            int j = height.size() - 1;
            while (i < j) {
                int area = (j-i) * (height[i] < height[j] ? height[i] : height[j]);
                result = result > area ? result : area;
                if (height[i] < height[j]) {
                    i++;
                } else {
                    j--;
                }
            }
            return result;
        }
};

void test(vector<int>& height) {
    cout <<"[";
    for (int i = 0; i < height.size(); ++i) {
        cout << height[i];
        if (i == height.size() -1) {
            cout << "]";
        } else {
            cout << ", ";
        }
    }
    Solution s;
    cout << " maxArea = " << s.maxArea(height) <<endl;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,3};
    test(a);
    vector<int> b = {1,1,3,1,3};
    test(b);
    return 0;
}
