/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int m=INT_MIN;
        int c=0;
        int res=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            int sum=0;
            while(k--){
                TreeNode* n=q.front();
                q.pop();
                sum+=n->val;
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            c++;
            if(m<sum){
                res=c;
                m=sum;
            }
        }
        return res;
    }
};