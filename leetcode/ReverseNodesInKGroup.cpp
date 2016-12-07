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
        if (k == 1 || k == 0) {
            return head;
        }
        //k=2;
        ListNode* result = NULL;
        ListNode* next = head;
        ListNode** cur = &result;
        while(next) {
            /*
             * store the current left, if no enough element for reverse
             * the left will add to the tail of the list.
             */
            ListNode* left = next;
            int i = 0;
            for(i = 0; i < k; ++i) {
                if (next == NULL) {
                    break;
                }
                next = next->next;
            }

            if (next != NULL || i == k) {
                /*
                 * elements is enough for a reverse
                 * when i == k, the left elements have k elements for reverse
                 */
                ListNode* t = reverseListN(head, 0, k);
                if ((*cur) == NULL) {
                    *cur = t;
                } else {
                    while((*cur)->next) {
                        cur = &(*cur)->next;
                    }
                    (*cur)->next = t;
                }
                head = next;
            } else {
                /*
                 * elements not enough for a reverse
                 */
                if ((*cur) == NULL) {
                    *cur = left;
                }else {
                    while((*cur)->next) {
                        cur = &(*cur)->next;
                    }
                    (*cur)->next = left;
                }
            }
        }
        return result;
    }

    ListNode* reverseListN(ListNode* head, int i, int n) {
        i++;
        if (head == NULL || head->next == NULL || i >= n) {
            return head;
        }
        ListNode* p = NULL;
        /*
         * 1 -> 2 -> 3 -> 4 -> 5  => 1 -> 2 <- 3 <- 4 <- 5
         */
        p = reverseListN(head->next, i, n);
        /*
         * 1 -> 2 <- 3 <- 4 <- 5 => <-> 2 <- 3 <- 4 <- 5
         * after head->next->next = head,  the head has a next point back to 2
         */
        head->next->next = head;
        /*
         * 1 <-> 2 <- 3 <- 4 <- 5 => 1 <- 2 <- 3 <- 4 <- 5
         */
        head->next = NULL;

        // p point to the last element, which is the new head;
        return p;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p = NULL;
        /*
         * 1 -> 2 -> 3 -> 4 -> 5  => 1 -> 2 <- 3 <- 4 <- 5
         */
        p = reverseList(head->next);
        /*
         * 1 -> 2 <- 3 <- 4 <- 5 => <-> 2 <- 3 <- 4 <- 5
         * after head->next->next = head,  the head has a next point back to 2
         */
        head->next->next = head;
        /*
         * 1 <-> 2 <- 3 <- 4 <- 5 => 1 <- 2 <- 3 <- 4 <- 5
         */
        head->next = NULL;

        // p point to the last element, which is the new head;
        return p;
    }

};


TEST(ReverseNodesInKGroup, k_is_1) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2,3,4,5});
    h->print();
    h = s.reverseKGroup(h, 1);
    h->print();
    EXPECT_EQ(h->at(0), 1);
    EXPECT_EQ(h->at(1), 2);
    EXPECT_EQ(h->at(2), 3);
    EXPECT_EQ(h->at(3), 4);
    EXPECT_EQ(h->at(4), 5);
}
TEST(ReverseNodesInKGroup, k_is_2) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2,3,4,5});
    h->print();
    h = s.reverseKGroup(h, 2);
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
    h = s.reverseKGroup(h, 3);
    h->print();
    EXPECT_EQ(h->at(0), 3);
    EXPECT_EQ(h->at(1), 2);
    EXPECT_EQ(h->at(2), 1);
    EXPECT_EQ(h->at(3), 4);
    EXPECT_EQ(h->at(4), 5);
}

TEST(ReverseNodesInKGroup, only2) {
    Solution s;
    ListNode* h = ListNode::createFromContainer(vector<int>{1,2});
    h->print();
    h = s.reverseKGroup(h, 2);
    h->print();
    EXPECT_EQ(h->at(0), 2);
    EXPECT_EQ(h->at(1), 1);
}
