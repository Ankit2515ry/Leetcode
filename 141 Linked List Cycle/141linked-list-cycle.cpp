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
    bool hasCycle(ListNode *head) {
        //apply two nested while loop then check is we found same pointer again or not O(n2) time complexity

        //use set to take recod of pointers then iterate list if we found same pointer again cycle is present otherwise not present O(n) time and space complexity

        //O(n) time complexity (Floyd’s Algorithm)
        ListNode* s=head;
        ListNode* f=head;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
            if(s==f)return true;
        }
        return false;
    }
};