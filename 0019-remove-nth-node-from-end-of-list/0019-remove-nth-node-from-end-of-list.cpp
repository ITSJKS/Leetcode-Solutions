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
    ListNode* reverseList(ListNode* head){
        if(head == nullptr) return head;
        ListNode* cur = head, *prev = nullptr, *next = nullptr;
        while(cur != nullptr){
            next  = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = reverseList(head);
        head = dummy;
        ListNode* prev = nullptr;
        ListNode* cur = dummy;
        for(int i = 0; i <n; i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        return reverseList(head->next);
    }
};