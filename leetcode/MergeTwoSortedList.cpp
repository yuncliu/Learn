/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
Subscribe to see which companies asked this question
*/
#include <iostream>
#include "gtest/gtest.h"
#include "ListNode.h"
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
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** x = &head;
        while(l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    //head = l1;
                    *x = l1;
                    x = &(*x)->next;
                    l1 = l1->next;
                } else {
                    *x = l2;
                    x = &(*x)->next;
                    l2 = l2->next;
                }
            }
            if (l1 && !l2) {
                *x = l1;
                x = &(*x)->next;
                l1 = l1->next;
            }
            if (!l1 && l2) {
                *x = l2;
                x = &(*x)->next;
                l2 = l2->next;
            }
        }
        return head;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** x = &head;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                //head = l1;
                *x = l1;
                x = &(*x)->next;
                l1 = l1->next;
            } else {
                *x = l2;
                x = &(*x)->next;
                l2 = l2->next;
            }
        }
        *x = l1 ? l1 : l2;
        return head;
    }

    ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoListsRecursive(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoListsRecursive(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergeTwoListsRecursive(l1, l2);
    }
};

TEST(MergeTwoSortedList, test1) {
    Solution s;
    vector<int> a = {1, 3, 5, 7, 9};
    vector<int> b = {2, 4, 6, 8, 10};
    ListNode* l1 = ListNode::createFromContainer(a);
    ListNode* l2 = ListNode::createFromContainer(b);
    ListNode* head = s.mergeTwoLists(l1, l2);
    head->print();
    EXPECT_EQ((size_t)10, head->length());
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}

TEST(MergeTwoSortedList, test2) {
    Solution s;
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6, 8, 10};
    ListNode* l1 = ListNode::createFromContainer(a);
    ListNode* l2 = ListNode::createFromContainer(b);
    ListNode* head = s.mergeTwoLists(l1, l2);
    EXPECT_EQ((size_t)8, head->length());
    head->print();
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}

TEST(MergeTwoSortedList, test3) {
    Solution s;
    vector<int> b = {2, 4, 6, 8, 10};
    ListNode* l2 = ListNode::createFromContainer(b);
    ListNode* head = s.mergeTwoLists(NULL, l2);
    head->print();
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}

TEST(MergeTwoSortedList, test4) {
    Solution s;
    vector<int> b = {2, 4, 6, 8, 10};
    ListNode* l2 = ListNode::createFromContainer(b);
    ListNode* head = s.mergeTwoLists(l2, NULL);
    head->print();
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}
