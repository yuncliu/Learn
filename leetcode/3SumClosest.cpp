/*
 * 16. 3Sum Closest   Add to List QuestionEditorial Solution  My Submissions
 *
 * Given an array S of n integers, find three integers in S such that
 * the sum is closest to a given number, target. Return the sum of
 * the three integers. You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include <vector>
#include <iostream>
#include <math.h>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (size_t k = 2; k < nums.size(); k++) {
            if (k + 1 < nums.size() && nums[k] == nums[k + 1]) { // skip duplicates
                continue;
            }
            for (size_t i = 0, j = k - 1;  i < j;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target || (i > 0 && nums[i - 1] == nums[i])) { // check sum skip duplicates
                    i++;
                }
                else if (sum > target || (j + 1 < k && nums[j + 1] == nums[j])) { // check sum skip duplicates
                    j--;
                } else {
                    i++;
                    j--;
                }
                closest = abs(closest - target) > abs(sum - target) ? sum : closest;
            }
        }
        return closest;
    }
};

TEST(threeSumClosest, test1) {
    Solution s;
    vector<int> num = { -1, 2, 1 , -4};
    EXPECT_EQ(s.threeSumClosest(num, 1), 2);
}

TEST(threeSumClosest, test2) {
    Solution s;
    vector<int> num = { 0, 1, 2};
    EXPECT_EQ(s.threeSumClosest(num, 0), 3);
}

TEST(threeSumClosest, test3) {
    Solution s;
    vector<int> num = { 0, 0, 0};
    EXPECT_EQ(s.threeSumClosest(num, 1), 0);
}
