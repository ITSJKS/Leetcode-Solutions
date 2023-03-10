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
    // first approach , keep every node in a list in a vector , and take random numbers using the size and generate a random number
    vector <int> v;
    Solution(ListNode* head) {
        while(head!=nullptr){
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int size = v.size();
        int random = rand()%size;
        return v[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */