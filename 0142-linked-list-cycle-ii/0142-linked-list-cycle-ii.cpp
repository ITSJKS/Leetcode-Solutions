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
    ListNode *detectCycle(ListNode *head) {
        // tortoise and hare , we start from same point with x and 2x speed, if we meet before slow reaches end we have a cycle else our fast will reach end and we won't have any cycle
        // the position of cycle can be founded by starting another pointer from start and moving fast and slow until they meet again
        if(head == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode* slow1 = head;
                while(slow!=slow1){
                    slow = slow->next;
                    slow1 = slow1->next;
                }
                return slow1;
            }
        }
        return nullptr;
    }
};