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
        int mini=-1;
        int maxi=-1;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=curr->next;
        vector<int>idx;
        int i=2;
        while(next!=nullptr){
            if(curr->val<prev->val&&curr->val<next->val)idx.push_back(i);
            if(curr->val>prev->val&&curr->val>next->val)idx.push_back(i);
            prev=curr;
            curr=next;
            next=next->next;
            i++;
        }
        if(idx.size()<2)return {mini,maxi};
        mini=INT_MAX;
        for(int i=1;i<idx.size();i++){
            mini=min(mini,idx[i]-idx[i-1]);
        }
        maxi=idx[idx.size()-1]-idx[0];
        return {mini,maxi}; 
    }
};