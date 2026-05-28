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
    void deleteNode(ListNode* node) {
        //O(n) time complexity
        // ListNode* curr=node->next;
        // ListNode* pre=node;
        // while(curr->next!=nullptr){
        //     pre->val=curr->val;
        //     pre=curr;
        //     curr=curr->next;
        // }
        // pre->val=curr->val;
        // pre->next=nullptr;

        //O(1) solution
        ListNode* curr=node->next;
        ListNode* pre=node;
        pre->val=curr->val;
        pre->next=curr->next;
        delete curr;
    }
};