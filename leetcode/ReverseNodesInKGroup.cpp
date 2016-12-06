/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */

#include <vector>
#include "ListNode.h"
#include "gtest/gtest.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return head;
    }
};


TEST(ReverseNodesInKGroup, k_is_2) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2,3,4,5});
    h->print();
    s.reverseKGroup(h, 2);
    h->print();
    EXPECT_EQ(h->at(0), 2);
    EXPECT_EQ(h->at(1), 1);
    EXPECT_EQ(h->at(2), 4);
    EXPECT_EQ(h->at(3), 3);
    EXPECT_EQ(h->at(4), 5);
}

TEST(ReverseNodesInKGroup, k_is_3) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2,3,4,5});
    h->print();
    s.reverseKGroup(h, 2);
    h->print();
    EXPECT_EQ(h->at(0), 3);
    EXPECT_EQ(h->at(1), 2);
    EXPECT_EQ(h->at(2), 1);
    EXPECT_EQ(h->at(3), 4);
    EXPECT_EQ(h->at(4), 5);
}
