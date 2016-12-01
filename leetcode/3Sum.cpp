/*
15. 3Sum   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 164657
Total Submissions: 798592
Difficulty: Medium
Contributors: Admin
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    /*
     * exceed time limit
     */
    vector<vector<int> > threeSumExceedTimeLimit(vector<int>& nums) {
        vector<vector<int> > result;
        //int crub[nums.size() + 1][nums.size() + 1][nums.size() + 1];
        vector<int> c1(nums.size() + 1);
        vector<vector<int> > c2;
        vector<vector<vector<int> > > crub;
        for (size_t i = 0; i < nums.size() + 1; ++i) {
            c2.push_back(c1);
        }

        for (size_t i = 0; i < nums.size() + 1; ++i) {
            crub.push_back(c2);
        }
        /* the (0, 0) point should left behind
         *   0 1 2 3
         *   --------
           0|# 1 2 3
           1|1 2 3 4
           2|2 3 4 5
           3|3 4 5 6
         */
        for (size_t i = 0; i < nums.size(); ++i) {
            crub[i + 1][0][0] = nums[i];
            crub[0][i + 1][0] = nums[i];
            crub[0][0][i + 1] = nums[i];
        }

        //for (size_t x = 1; x < nums.size() + 1; ++x) {
        //  for (size_t y = 1; y < nums.size() + 1; ++y) {
        //      for (size_t z = 1; z < nums.size() + 1; ++z) {
        for (size_t x = 1; x < nums.size() + 1; ++x) {
            for (size_t y = 1; y < x; ++y) {
                for (size_t z = 1; z < y; ++z) {
                    crub[x][y][z] = crub[x][0][0] + crub[0][y][0] + crub[0][0][z];
                    if ( crub[x][y][z] == 0 && z < y && y < x) {
                        vector<int> t;
                        t.push_back(nums[x-1]);
                        t.push_back(nums[y-1]);
                        t.push_back(nums[z-1]);
                        sort(t.begin(), t.end());
                        if (result.empty()) {
                            result.push_back(t);
                        } else {
                            // check if the vector is alreay exist
                            bool exist = false;
                            for (auto v : result) {
                                size_t num_of_same = 0;
                                while(v.size() == t.size()
                                      && v[num_of_same] == t[num_of_same] && num_of_same < t.size()) {
                                    num_of_same++;
                                }
                                if (num_of_same == t.size()) {
                                    exist = true;
                                }
                            }
                            if (!exist) {
                                result.push_back(t);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (size_t k = 2; k < nums.size(); k++) {
            if (k + 1 < nums.size() && nums[k] == nums[k + 1]) { // skip duplicates
                continue;
            }
            for (size_t i = 0, j = k - 1;  i < j;) {
                int sum = nums[i] + nums[j];
                int target = 0 - nums[k];
                if (sum < target || (i > 0 && nums[i - 1] == nums[i])) { // check sum skip duplicates
                    i++;
                }
                else if (sum > target || (j + 1 < k && nums[j + 1] == nums[j])) { // check sum skip duplicates
                    j--;
                }
                else {
                    result.push_back({nums[i++], nums[j--], nums[k]});// pust into result
                }
            }
        }
        return result;
    }
};
#if 1
TEST(threeSum, test) {
    Solution s;
    vector<int> num = { -1, 0, 1, 2, -1 , -4};
    vector<vector<int> > result = s.threeSum(num);
    EXPECT_EQ(result.size(), (size_t)2);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            cout << n << ", ";
            sum += n;
        });
        cout << "]" << endl;;
        EXPECT_EQ(sum, 0);
    }
}
#endif
#if 1
TEST(threeSum, test1) {
    Solution s;
    vector<int> num = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    vector<vector<int> > result = s.threeSum(num);
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            cout << n << ", ";
            sum += n;
        });
        cout << "]" << endl;;
        EXPECT_EQ(sum, 0);
    }
}
#endif
#if 1
TEST(threeSum, all_zero) {
    Solution s;
    vector<int> num = {0, 0, 0};
    vector<vector<int> > result = s.threeSum(num);
    EXPECT_EQ(result.size(), (size_t)1);
    cout << "all zero" <<endl;
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            cout << n << ", ";
            sum += n;
        });
        cout << "]" << endl;;
        EXPECT_EQ(sum, 0);
    }
}
#endif

#if 1
TEST(threeSum, time_limit) {
    Solution s;
    vector<int> num = {5,-9,-11,9,9,-4,14,10,-11,1,-13,11,10,14,-3,-3,-4,6,-15,6,6,-13,7,-11,-15,10,-8,13,-14,-12,12,6,-6,8,0,10,-11,-8,-2,-6,8,0,12,3,-9,-6,8,3,-15,0,-6,-1,3,9,-5,-5,4,2,-15,-3,5,13,-11,7,6,-4,2,11,-5,7,12,-11,-15,1,-1,-9,10,-8,1,2,8,11,-14,-4,-3,-12,-2,8,5,-1,-9,-4,-3,-13,-12,-12,-10,-3,6,1,12,3,-3,12,11,11,10};
    vector<vector<int> > result = s.threeSum(num);
    EXPECT_EQ(result.size(), (size_t)108);
    cout << "size is " << result.size() <<endl;
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = 0;
        cout << "[ ";
        for_each(result[i].begin(), result[i].end(), [&](int n){
            cout << n << ", ";
            sum += n;
        });
        cout << "]" << endl;;
        EXPECT_EQ(sum, 0);
    }
}
#endif
