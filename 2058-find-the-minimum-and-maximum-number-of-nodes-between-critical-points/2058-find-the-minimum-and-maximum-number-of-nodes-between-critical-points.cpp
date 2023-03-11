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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        vector <int> v;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        vector <int> c_p;
        for(int i = 1; i <n-1; i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]) c_p.push_back(i);
            else if(v[i]<v[i-1] && v[i]<v[i+1]) c_p.push_back(i);
        }
        if(c_p.size() < 2) return {-1,-1};
        int maxi = c_p.back() - c_p[0];
        int mini = INT_MAX;
        for(int i = 1; i <c_p.size(); i++){
            mini = min(c_p[i]-c_p[i-1],mini);
        }
        return {mini,maxi};
    }
};