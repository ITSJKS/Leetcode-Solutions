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
    int find_length(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
       int length = find_length(head);
        if(length== 1) return nullptr;
        int mid = length/2;
        ListNode* temp = head;
        for(int i = 0; i <mid-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
        
    }
};