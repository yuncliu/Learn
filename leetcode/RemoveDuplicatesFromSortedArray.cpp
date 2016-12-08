/*
 * Given a sorted array, remove the duplicates in
 * place such that each element appear only once
 * and return the new length.
 *
 * Do not allocate extra space for another array,
 * you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with
 * the first two elements of nums being 1 and 2
 * respectively. It doesn't matter what you leave
 * beyond the new length.
 */

#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
    public:
    /*
     * sometime 52, sometime 36, sometime 27
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int>::size_type count = 0;
        for (vector<int>::size_type i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                nums[i - count] = nums[i];
            }
        }
        return nums.size() - count;
    }
    /*
     * beats 36 % submissions
     */
    int removeDuplicatesBeats36Percent(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int>::size_type pos = 0;
        for (vector<int>::size_type i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[pos]) {
                nums[++pos] = nums[i];
            }
        }
        return pos + 1;
    }
};


TEST(RemoveDuplicatesFromSortedArray, test1) {
    Solution s;
    vector<int> nums = {1, 1, 2};
    EXPECT_EQ(s.removeDuplicates(nums), 2);
    EXPECT_EQ(1, nums[0]);
    EXPECT_EQ(2, nums[1]);
}

TEST(RemoveDuplicatesFromSortedArray, test2) {
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4};
    EXPECT_EQ(s.removeDuplicates(nums), 4);
    EXPECT_EQ(1, nums[0]);
    EXPECT_EQ(2, nums[1]);
    EXPECT_EQ(3, nums[2]);
    EXPECT_EQ(4, nums[3]);
}

TEST(RemoveDuplicatesFromSortedArray, test3) {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(s.removeDuplicates(nums), 1);
    EXPECT_EQ(1, nums[0]);
}

TEST(RemoveDuplicatesFromSortedArray, test4) {
    Solution s;
    vector<int> nums = {};
    EXPECT_EQ(s.removeDuplicates(nums), 0);
}

TEST(RemoveDuplicatesFromSortedArray, test5) {
    Solution s;
    vector<int> nums = {1};
    EXPECT_EQ(s.removeDuplicates(nums), 1);
    EXPECT_EQ(nums[0], 1);
}
