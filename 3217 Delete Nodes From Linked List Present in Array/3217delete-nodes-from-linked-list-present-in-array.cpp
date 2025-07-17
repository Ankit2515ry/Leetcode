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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for(int i=0;i<nums.size();i++)st.insert(nums[i]);
        ListNode* dummy=new  ListNode(-1);
        ListNode* temp =head;
        ListNode* temp1 =dummy;
        while(temp){
            if(st.find(temp->val)!=st.end()){
                temp=temp->next;
            }
            else{
                temp1->next=new ListNode(temp->val);
                temp=temp->next;
                temp1=temp1->next;
            }
        }
        return dummy->next;
    }
};