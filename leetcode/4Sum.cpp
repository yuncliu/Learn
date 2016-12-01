/*

18. 4Sum
https://leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        // i, j, k, l
        for(size_t i = 0, l = nums.size() - 1; i < l - 2;) {
            /*
            if (i + 1 < l - 2 && nums[i] == nums[i + 1]) {
                i++;
                continue;
            }
            if (l - 3 > i && nums[ l-1 ] == nums[l]) {
                l--;
                continue;
            }
            */

            for(size_t j = i + 1, k = l - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum > target || (k - 1 > j && nums[k] == nums[k - 1])) {
                    k--;
                } else if (sum < target || (j + 1 < k && nums[j] == nums[j + 1])) {
                    j++;
                } else {
                    result.push_back({nums[i],nums[j],nums[k],nums[l]});
                    j++;
                    k--;
                }
            }
            int sum = nums[i] +nums[i+1] + nums[l-1] + nums[l];
            /* here shoud handle when sum == target , test8 failed*/
            if (sum > target) {
                l--;
            } else {
                i++;
            }
        }
        return result;
    }
};
#if 1
TEST(fourSum, example) {
    /*
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
    Solution s;
    vector<int> num = {1, 0, -1, 0, -2, 2};
    vector<vector<int> > result = s.fourSum(num, 0);
    EXPECT_EQ(result.size(), (size_t)3);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
        });
        EXPECT_EQ(sum, 0);
    }
}
#endif
#if 1
TEST(fourSum, test2) {
    Solution s;
    vector<int> num = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    vector<vector<int> > result = s.fourSum(num, 0);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
        });
        EXPECT_EQ(sum, 0);
    }
}
#endif
#if 1
TEST(fourSum, test3) {
    Solution s;
    vector<int> num = {0, 0, 0, 0};
    vector<vector<int> > result = s.fourSum(num, 0);
    EXPECT_EQ(result.size(), (size_t)1);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
        });
        EXPECT_EQ(sum, 0);
    }
}

TEST(fourSum, test4) {
    Solution s;
    vector<int> num = {1,0,-1,0,-2,2};
    vector<vector<int> > result = s.fourSum(num, 0);
    EXPECT_EQ(result.size(), (size_t)3);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
            cout << n << ", ";
        });
        cout << "]" <<endl;
        EXPECT_EQ(sum, 0);
    }
}

TEST(fourSum, test5) {
    Solution s;
    vector<int> num = {-3,-1,0,2,4,5};
    vector<vector<int> > result = s.fourSum(num, 2);
    EXPECT_EQ(result.size(), (size_t)1);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
            cout << n << ", ";
        });
        cout << "]" <<endl;
        EXPECT_EQ(sum, 2);
    }
}

TEST(fourSum, test6) {
    Solution s;
    vector<int> num = {-3,-1,0,2,4,5};
    vector<vector<int> > result = s.fourSum(num, 0);
    EXPECT_EQ(result.size(), (size_t)1);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
            cout << n << ", ";
        });
        cout << "]" <<endl;
        EXPECT_EQ(sum, 0);
    }
}

TEST(fourSum, test7) {
    Solution s;
    vector<int> num = {-1,0,1,2,-1,-4};
    vector<vector<int> > result = s.fourSum(num, -1);
    EXPECT_EQ(result.size(), (size_t)2);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
            cout << n << ", ";
        });
        cout << "]" <<endl;
        EXPECT_EQ(sum, -1);
    }
}
TEST(fourSum, test8) {
    Solution s;
    vector<int> num = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int> > result = s.fourSum(num, 0);
    EXPECT_EQ(result.size(), (size_t)8);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
            cout << n << ", ";
        });
        cout << "]" <<endl;
        EXPECT_EQ(sum, 0);
    }
}
#endif

#if 1
TEST(fourSum, time_limit) {
    Solution s;
    vector<int> num = {5,-9,-11,9,9,-4,14,10,-11,1,-13,11,10,14,-3,-3,-4,6,-15,6,6,-13,7,-11,-15,10,-8,13,-14,-12,12,6,-6,8,0,10,-11,-8,-2,-6,8,0,12,3,-9,-6,8,3,-15,0,-6,-1,3,9,-5,-5,4,2,-15,-3,5,13,-11,7,6,-4,2,11,-5,7,12,-11,-15,1,-1,-9,10,-8,1,2,8,11,-14,-4,-3,-12,-2,8,5,-1,-9,-4,-3,-13,-12,-12,-10,-3,6,1,12,3,-3,12,11,11,10};
    vector<vector<int> > result = s.fourSum(num, 0);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        for_each(result[i].begin(), result[i].end(), [&](int n){
            sum += n;
        });
        EXPECT_EQ(sum, 0);
    }
}
#endif
