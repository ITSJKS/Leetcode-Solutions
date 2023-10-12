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
    ListNode* reverse(ListNode* head){
        int count = 0;
        ListNode* cur = head, *prev = nullptr, *next = nullptr;
        while(cur!=nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int cnt = 1;
        if(head == nullptr) return head;
        while(cur->next!=nullptr && cnt < k){
            cur = cur->next;
            cnt++;
        }
        if(cnt < k) return head;
        ListNode* next = cur->next;
        cur->next = nullptr;
        ListNode* nextGroup = reverseKGroup(next,k);
        ListNode* temp = reverse(head);
        head->next = nextGroup;
        return temp;
    }
};