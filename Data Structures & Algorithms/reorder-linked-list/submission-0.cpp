/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* fp = head;
        ListNode* sp = head;
        while (fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;
        }

        ListNode* rmid = sp->next;
        sp->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* cur = rmid;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* rlist = prev;

        ListNode* list1 = head;
        ListNode* list2 = rlist;
        while (list1 && list2) {
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;

            list1->next = list2;
            list2->next = next1;

            list1 = next1;
            list2 = next2;
        }
    }
};
