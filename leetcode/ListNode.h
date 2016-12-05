#ifndef _LISTNODE_H_
#define _LISTNODE_H_
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x);
    int length();
    void push_back(int x);
};

#endif // _LISTNODE_H_
