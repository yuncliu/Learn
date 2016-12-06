/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 *      Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space.
 * You may not modify the values in the list, only nodes itself can be changed.
 * https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode** p = &head;
        ListNode* current = NULL;
        ListNode* next = NULL;
        while((*p)) {
            // slow must not NULL
            current = *p;
            next = current->next;
            // but fast is possible to be NULL;
            if (!next) {
                break;
            }

            // swap current and next.
            current->next = next->next;
            next->next = current;
            *p = next;

            p = &current->next;
        }
        return head;
    }
};


TEST(SwapNodesInPairs, test1) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2,3,4});
    h->print();
    h = s.swapPairs(h);
    h->print();
    EXPECT_EQ(h->at(0), 2);
    EXPECT_EQ(h->at(1), 1);
    EXPECT_EQ(h->at(2), 4);
    EXPECT_EQ(h->at(3), 3);
    ListNode::destroy(h);
}

TEST(SwapNodesInPairs, test2) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2,3});
    h->print();
    h = s.swapPairs(h);
    h->print();
    EXPECT_EQ(h->at(0), 2);
    EXPECT_EQ(h->at(1), 1);
    EXPECT_EQ(h->at(2), 3);
    ListNode::destroy(h);
}
