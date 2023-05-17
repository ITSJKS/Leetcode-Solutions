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
    int pairSum(ListNode* head) {
        ListNode* node1 = head;
        ListNode* node2 = head;
        while(node2!=nullptr && node2->next){
            node1 = node1->next;
            node2 = node2->next->next;
        }
        ListNode* next_node, *prev = NULL;
        while(node1){
            next_node = node1->next;
            node1->next = prev;
            prev = node1;
            node1 = next_node;
        }
        int maxi = 0;
        ListNode* start = head;
        while(prev){
            maxi = max(maxi,prev->val + start->val);
            start = start->next;
            prev = prev->next;
        }
        return maxi;
    }
};