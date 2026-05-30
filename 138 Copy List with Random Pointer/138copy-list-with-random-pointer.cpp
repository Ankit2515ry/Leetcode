/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //O(n) time and space complexity
        //if(!head)return nullptr;
        // Node dummy(0);
        // Node* temp=&dummy;
        // Node* it=head;
        // unordered_map<Node*,Node*>mp;
        // while(it){
        //     temp->next=new Node(it->val);
        //     mp[it]=temp->next;
        //     temp=temp->next;
        //     it=it->next;
        // }
        // it=head;
        // temp=dummy.next;
        // while(it){
        //     if(it->random){
        //         temp->random=mp[it->random];
        //     }
        //     temp=temp->next;
        //     it=it->next;
        // }
        // return dummy.next;

        //O(n) time complexity
        Node* temp=head;
        while(temp){
            Node* add=new Node(temp->val);
            add->next=temp->next;
            temp->next=add;
            temp=add->next;
        }
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node* dummy=new Node(-1);
        Node* it=dummy;
        temp=head;
        while(temp){
            Node* sep=temp->next;
            temp->next=sep->next;
            it->next=sep;
            it=it->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};