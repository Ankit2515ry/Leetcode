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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>>matrix(n,vector<int>(m,-1));
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        int x=0;
        vector<int>temp;
        ListNode* a=head;
        while(a!=nullptr){
            temp.push_back(a->val);
            a=a->next;
        }
        int b=temp.size();
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++){
                if(x<b)matrix[top][j]=temp[x];
                x++;
            }
            top++;
            for (int i = top; i <= bottom; i++){
                if(x<b)matrix[i][right]=temp[x];
                x++;
            }
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--){
                    if(x<b)matrix[bottom][j]=temp[x];
                    x++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--){
                    if(x<b)matrix[i][left]=temp[x];
                    x++;
                }
                left++;
            }
        }
        return matrix;
    }
};