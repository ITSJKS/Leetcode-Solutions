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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> s1,s2;
        while(l1!=nullptr){
            s1.push(l1->val);
            l1= l1->next;
        }
        while(l2!=nullptr){
            s2.push( l2->val );
            l2 = l2->next;
        }
        int cur_sum = 0 , carry = 0;
        ListNode* ans = new ListNode();
        while(s1.size() || s2.size()){
            if(s1.size()){
                cur_sum += s1.top();
                s1.pop();
            }
            if(s2.size()){
                cur_sum += s2.top();
                s2.pop();
            }
            ans->val = cur_sum%10;
            carry = cur_sum/10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            cur_sum = carry;
        }
        if(carry == 0) return ans->next;
        return ans;
    }
};