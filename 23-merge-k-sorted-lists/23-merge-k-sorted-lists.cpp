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
    typedef pair <int, ListNode*> pii;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue <pii , vector <pii> , greater <pii>> pq;
        for(auto x:lists){
            if(x!=NULL)
            pq.push({x->val,x});
        }
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(!pq.empty()){
            ListNode* node = pq.top().second;
            pq.pop();
            if(node->next!=NULL) pq.push({node->next->val,node->next});
         temp->next  = node;
         temp = temp->next;
        }
        return head->next;
        
    }
};