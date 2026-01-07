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
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        root->val=l+r+root->val;
        return root->val;
    }
    int maxProduct(TreeNode* root) {
        int ts=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            ts+=q.front()->val;
            TreeNode* n=q.front();
            q.pop();
            if(n->left!=nullptr)q.push(n->left);
            if(n->right!=nullptr)q.push(n->right);
        }
        dfs(root);
        //cout<<ts;
        long long res=0;
        long long mod=1e9+7;
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            long long a=ts-(n->val);
            long long b=n->val;
            long long temp=(a*b);
            res=max(res,temp);
            if(n->left!=nullptr)q.push(n->left);
            if(n->right!=nullptr)q.push(n->right);
        }
        return (int)(res%mod);  
    }
};