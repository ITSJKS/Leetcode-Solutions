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
    ListNode* mhead;
    Solution(ListNode* head) {
        mhead = head;
    }
    
    int getRandom() {
        ListNode* curr = mhead;
        int scope = 1, ans = 0;
        while(curr!=nullptr){
            if(rand()%scope == 0){
                ans = curr->val;
            }
            curr= curr->next;
            scope++;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */