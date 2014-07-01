// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    void reorderList(ListNode *head) {
        if(!head) return;
        ListNode *first = head, *second = head;
        while(second && second->next) {
            second = second->next->next;
            first = first->next;
        }
        ListNode *tail = revList(first->next);
        first->next = NULL;
        while(tail) {
            ListNode *nextHead = head->next;
            ListNode *nextTail = tail->next;
            head->next = tail;
            tail->next = nextHead;
            head = nextHead;
            tail = nextTail;
        }
    }
    
    ListNode *revList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
