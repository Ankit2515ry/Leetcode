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
    int getDecimalValue(ListNode* head) {
        int value=0;
        int j=1;
        ListNode* temp=head;
        while(temp){
            j*=2;
            temp=temp->next;
        }
        j/=2;
        temp=head;
        while(temp){
            if(temp->val==1){
                value+=j;
                j/=2;
                temp=temp->next;
            }else{
            j/=2;
            temp=temp->next;
            }
        }
        return value;
    }
};