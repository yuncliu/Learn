/*
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/
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
    Solution():count(0), while_loop(0) {
    }
    /*
     * divide and conquer is far more fast
     * beats 89.10% of cpp submissions
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = (int)lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
        return doMerge(lists, 0, (int)lists.size()-1);
    }
    ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
        if(left==right) return lists[left];
        else if(left+1==right) return mergeTwoLists2(lists[left], lists[right]);
        ListNode* l1 = doMerge(lists, left, (left+right)/2);
        ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
        return mergeTwoLists2(l1, l2);
    }

    /*
     * if use this instead.
     * but runtime in leetcode is around 349 ms
     * beats 4.25% cpp submissions.
     */
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        count++;
        ListNode* head = NULL;
        ListNode** x = &head;
        while(l1 && l2) {
            while_loop++;
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


    /*
     * reuse the algorithm in mergeTwoLists it is so sample.
     * but runtime in leetcode is around 500 ms
     * beats 2.23% of cpp submissions.
     */
    ListNode* mergeKListsSlow(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        for (auto i : lists) {
            head = mergeTwoLists2(head, i);
        }
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
    int count;
    int while_loop;
};

TEST(MergeKSortedList, test1) {
    Solution s;
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};
    vector<int> v3 = {7,8,9};
    ListNode* l1 = ListNode::createFromContainer(v1);
    ListNode* l2 = ListNode::createFromContainer(v2);
    ListNode* l3 = ListNode::createFromContainer(v3);
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* head = s.mergeKLists(lists);
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}

TEST(MergeKSortedList, test2) {
    Solution s;
    vector<int> v1 = {1,4,7};
    vector<int> v2 = {2,5,8};
    vector<int> v3 = {3,6,9};
    ListNode* l1 = ListNode::createFromContainer(v1);
    ListNode* l2 = ListNode::createFromContainer(v2);
    ListNode* l3 = ListNode::createFromContainer(v3);
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* head = s.mergeKLists(lists);
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}

TEST(MergeKSortedList, test3) {
    Solution s;
    vector<ListNode*> lists;
    for (int i = 0; i < 1024; ++i) {
        vector<int> v = {1,4,7};
        ListNode* l = ListNode::createFromContainer(v);
        lists.push_back(l);
    }
    ListNode* head = s.mergeKLists(lists);
    cout << "called MergeTwoSortedList2 " << s.count << "times" <<endl;
    cout << "called MergeTwoSortedList2  while loops :" << s.while_loop << "times" << endl;
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}

TEST(MergeKSortedList, test3slow) {
    Solution s;
    vector<ListNode*> lists;
    for (int i = 0; i < 1024; ++i) {
        vector<int> v = {1,4,7};
        ListNode* l = ListNode::createFromContainer(v);
        lists.push_back(l);
    }
    ListNode* head = s.mergeKListsSlow(lists);
    cout << "called MergeTwoSortedList2 " << s.count << "times" <<endl;
    /*
     * The while loop in the MergeTwoSortedList2 loops far more times than divide and conquer.
     * That's why the divide and conquer is far more fast
     */
    cout << "called MergeTwoSortedList2  while loops :" << s.while_loop << "times" << endl;
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
    ListNode::destroy(head);
}
