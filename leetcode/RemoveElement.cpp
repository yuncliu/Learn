/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2, with the first two elements of nums being 2.
 *
 * https://leetcode.com/problems/remove-element/
 */

#include <vector>
#include "gtest/gtest.h"
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.empty()) {
                return 0;
            }
            vector<int>::size_type pos = 0;
            for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
                if (nums[i] != val) {
                    nums[pos++] = nums[i];
                }
            }
            return pos;
        }
};

TEST(removeElement, test1) {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    EXPECT_EQ(s.removeElement(nums, 3), 2);
    EXPECT_EQ(nums[0], 2);
    EXPECT_EQ(nums[1], 2);
}

TEST(removeElement, test2) {
    Solution s;
    vector<int> nums = {2};
    EXPECT_EQ(s.removeElement(nums, 3), 1);
    EXPECT_EQ(nums[0], 2);
}

TEST(removeElement, test3) {
    Solution s;
    vector<int> nums = {3,3,3,3,3};
    EXPECT_EQ(s.removeElement(nums, 3), 0);
}
