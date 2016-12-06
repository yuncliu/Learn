#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include <stddef.h>
#include <list>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x);
    size_t length();
    void push_back(int x);
    void print();
    list<int> get_list();
    int at(size_t index);
    static ListNode* create(int x);
    static void destroy(ListNode* head);
    template<class T>
    static ListNode* createFromContainer(T l) {
        ListNode* head = NULL;
        for (auto it : l) {
            if (head) {
                head->push_back(it);
            }else {
                head = new ListNode(it);
            }
        }
        return head;
    }
};

#endif // _LISTNODE_H_
