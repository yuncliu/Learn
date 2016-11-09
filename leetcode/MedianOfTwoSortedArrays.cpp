/*
4. Median of Two Sorted Arrays
 QuestionEditorial Solution  My Submissions
Total Accepted: 127458
Total Submissions: 624285
Difficulty: Hard
Contributors: Admin
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

https://leetcode.com/problems/median-of-two-sorted-arrays/

*/

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>

using namespace std;

string vector_to_str(const vector<int>& v) {
    stringstream ssm;
    ssm << "[";
    for (int i = 0; i < v.size(); ++i) {
        ssm << v[i];
        if (i != v.size() - 1) {
            ssm << " ,";
        }
    }
    ssm << "]";
    return ssm.str();
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0;
        int j = 0;
        while(true) {
            if (i < nums1.size() && j < nums2.size() && nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else if (j < nums2.size()) {
                merged.push_back(nums2[j]);
                j++;
            } else if (i < nums1.size()) {
                merged.push_back(nums1[i]);
                i++;
            }

            if (merged.size() == nums1.size() + nums2.size()) {
                break;
            }
        }
        if (merged.size() % 2 == 1) {
            return (double)merged[merged.size() / 2];
        }else {
            return ((double)(merged[(merged.size() / 2) - 1] + merged[merged.size() / 2])) / 2;
        }
    }
};


void test(vector<int>& nums1, vector<int>& nums2) {
    Solution s;
    double median = s.findMedianSortedArrays(nums1, nums2);
    printf("%s %s [%f]\n", vector_to_str(nums1).c_str(), vector_to_str(nums2).c_str(), median);
}

int main(int argc, char *argv[]) {
    /*
    */
    {
        vector<int> a;
        a.push_back(1);
        vector<int> b;
        b.push_back(2);
        b.push_back(3);
        test(a, b);
    }
    {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        vector<int> b;
        b.push_back(2);
        b.push_back(3);
        test(a, b);
    }
    {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(4);
        a.push_back(5);
        vector<int> b;
        b.push_back(3);
        test(a, b);
    }
    {
        vector<int> a;
        vector<int> b;
        b.push_back(1);
        b.push_back(2);
        b.push_back(3);
        test(a, b);
    }
    {
        vector<int> a;
        a.push_back(2);
        vector<int> b;
        test(a, b);
    }
    return 0;
}
