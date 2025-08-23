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
    bool isSymmetric(TreeNode* root) {
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        queue<TreeNode*>a;
        queue<TreeNode*>b;
        a.push(p);
        b.push(q);
        while(!a.empty()&&!b.empty()){
            TreeNode* tempa=a.front();
            a.pop();
            TreeNode* tempb=b.front();
            b.pop();
            if(tempa==nullptr&&tempb==nullptr)continue;
            if(tempa==nullptr||tempb==nullptr||tempa->val!=tempb->val)return false;
            a.push(tempa->left);
            a.push(tempa->right);
            b.push(tempb->right);
            b.push(tempb->left);
        }
        return (a.size()==0)&&(b.size()==0);
    }
};