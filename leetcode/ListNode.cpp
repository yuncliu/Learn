#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "ListNode.h"

#include "gtest/gtest.h"

using namespace std;

ListNode::ListNode(int x)
:val(x), next(NULL) {
}

size_t ListNode::length() {
    ListNode* p = this;
    size_t len = 0;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

void ListNode::push_back(int x) {
    ListNode* p = this;
    while(p->next) {
        p = p->next;
    }
    p->next = new ListNode(x);
}
void ListNode::print() {
    cout << "[ ";
    ListNode* p = this;
    while(p) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "]" << endl;
}

list<int> ListNode::get_list() {
    list<int> l;
    ListNode* p = this;
    while(p) {
        l.push_back(p->val);
        p = p->next;
    }
    return l;
}

ListNode* ListNode::create(int x) {
    return new ListNode(x);
}

void ListNode::destroy(ListNode* head) {
    while(head != NULL) {
        ListNode* p = head;
        head = head->next;
        delete p;
    }
}

TEST(ListNode, CreateFromContainer) {
    vector<int> v = {1,2,3};
    ListNode* head = ListNode::createFromContainer(v);
    head->print();
    list<int> l = head->get_list();
    EXPECT_TRUE(is_sorted(l.begin(), l.end()));
}