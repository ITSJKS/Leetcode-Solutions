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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int l  = 0;
        if(head == NULL) return {};
        while(temp1->next){
            l++;
            temp1 = temp1->next;
        }
        l++;
        temp1->next = head;
        k = k%l;
        int count1 = l - k;
        int count = 0;
        ListNode* prev = NULL;
        while(count<count1){
            prev = temp2;
            temp2 = temp2->next;
            count++;
        }
        prev->next = NULL;
        return temp2;
        
    }
};