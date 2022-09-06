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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* check_k = head;
        for(int i = 0; i <k; i++){
            if(check_k==nullptr) return head;
            check_k = check_k->next;
        }
        int count = 0;
        ListNode* cur = head, *prev = NULL, *next = NULL;
        while(cur && count < k){
            count++;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(next){
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};