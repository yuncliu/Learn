/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes 1->2->3->5.
 *       Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
 *
 *       Subscribe to see which companies asked this question
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include "gtest/gtest.h"
#include "ListNode.h"
using namespace std;

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* nth_prev = NULL;
            ListNode* p = head;
            int len = 0;
            while(p != NULL) {
                p = p->next;
                len++;
                if (len == n + 1) {
                    /* mark the previous point of which to delete
                     */
                    nth_prev = head;
                } else if (nth_prev) {
                    // once nth_prev is assigned. it need begin to iterator.
                    nth_prev = nth_prev->next;
                }
            }

            if (nth_prev == NULL && n == len) {
                // delete head
                ListNode* t = head->next;
                delete head;
                return t;
            } else {
                ListNode* t = nth_prev->next;
                nth_prev->next = nth_prev->next->next;
                delete t;
                return head;
            }
        }
};

TEST(RemoveNthNodeFromEndOfList, test1) {
    Solution s;
    ListNode* h = ListNode::create(1);
    h->push_back(2);
    h->push_back(3);
    h->push_back(4);
    h->push_back(5);
    h->print();
    h = s.removeNthFromEnd(h, 1);
    h->print();
    ListNode::destroy(h);
}

TEST(RemoveNthNodeFromEndOfList, test2) {
    Solution s;
    ListNode* h = ListNode::create(1);
    h->push_back(2);
    h->push_back(3);
    h->push_back(4);
    h->push_back(5);
    h->print();
    h = s.removeNthFromEnd(h, 2);
    h->print();
    ListNode::destroy(h);
}

TEST(RemoveNthNodeFromEndOfList, test3) {
    Solution s;
    ListNode* h = ListNode::create(1);
    h->push_back(2);
    h->push_back(3);
    h->push_back(4);
    h->push_back(5);
    h->print();
    h = s.removeNthFromEnd(h, 3);
    h->print();
    ListNode::destroy(h);
}

TEST(RemoveNthNodeFromEndOfList, test5) {
    Solution s;
    ListNode* h = ListNode::create(1);
    h->push_back(2);
    h->push_back(3);
    h->push_back(4);
    h->push_back(5);
    h->print();
    h = s.removeNthFromEnd(h, 5);
    h->print();
    ListNode::destroy(h);
}
